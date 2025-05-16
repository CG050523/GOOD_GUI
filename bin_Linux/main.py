import http.server
import socketserver
import json
import os
from urllib.parse import parse_qs, urlparse
import webbrowser
import platform

import socket
import subprocess
import tempfile
import logging

# 设置日志
def setup_logging():
    log_format = '%(asctime)s - %(levelname)s - %(message)s'
    logging.basicConfig(
        level=logging.INFO,
        format=log_format,
        handlers=[
            logging.StreamHandler()
        ]
    )
    return logging.getLogger('server')

logger = setup_logging()



# 设置允许跨域请求的处理器
class CORSHTTPRequestHandler(http.server.SimpleHTTPRequestHandler):
    def end_headers(self):
        self.send_header('Access-Control-Allow-Origin', '*')
        self.send_header('Access-Control-Allow-Methods', 'GET, POST, OPTIONS')
        self.send_header('Access-Control-Allow-Headers', 'Content-Type')
        super().end_headers()
    
    def do_OPTIONS(self):
        self.send_response(200)
        self.end_headers()
    
    def do_GET(self):
        # 解析URL
        parsed_url = urlparse(self.path)
        path = parsed_url.path
        
        # 处理根路径请求，返回HTML文件
        if path == '/':
            self.send_response(200)
            self.send_header('Content-type', 'text/html')
            self.end_headers()
            with open('config_generator.html', 'rb') as file:
                self.wfile.write(file.read())
            return
        
        # 处理浏览目录请求
        if path == '/browse':
            query = parse_qs(parsed_url.query)
            dir_path = query.get('path', [''])[0]
            
            # 确保路径存在
            if not dir_path or not os.path.exists(dir_path):
                if platform.system() == 'Windows':
                    dir_path = 'C:\\'
                else:  # Linux, macOS, etc.
                    dir_path = '/'
            
            # 确保路径是目录
            if not os.path.isdir(dir_path):
                dir_path = os.path.dirname(dir_path)
            
            # 获取目录内容
            try:
                items = []
                for item in os.listdir(dir_path):
                    full_path = os.path.join(dir_path, item)
                    is_dir = os.path.isdir(full_path)
                    items.append({
                        'name': item,
                        'path': full_path,
                        'is_directory': is_dir
                    })
                
                # 按目录/文件排序
                items.sort(key=lambda x: (not x['is_directory'], x['name'].lower()))
                
                # 获取父目录
                parent_dir = os.path.dirname(dir_path)
                
                response = {
                    'current_path': dir_path,
                    'parent_directory': parent_dir,
                    'items': items
                }
                
                # 发送响应
                self.send_response(200)
                self.send_header('Content-type', 'application/json')
                self.end_headers()
                self.wfile.write(json.dumps(response).encode())
                return
            except Exception as e:
                self.send_error(500, str(e))
                return
        
        # 处理其他静态文件请求
        return super().do_GET()
    
    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length).decode('utf-8')
    
        # 解析URL
        parsed_url = urlparse(self.path)
        path = parsed_url.path
        # 处理下载请求
        if path == '/download':
            try:
                # 解析JSON数据
                import json
                data = json.loads(post_data)
                config_content = data.get('config', '')
        
                if not config_content:
                    self.send_error(400, 'Empty configuration')
                    return
        
                # 保存配置文件
                config_file = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'cfg_GOOD.yaml')
                with open(config_file, 'w') as f:
                    f.write(config_content)

                logger.info(f"Configuration saved to {config_file}")
        
                # 执行下载命令
                try:
                    logger.info("Starting data download...")
                    # 使用子进程执行命令
                    script_dir = os.path.dirname(os.path.abspath(__file__))
                    run_good_path = os.path.join(script_dir, 'run_GOOD')
                    # 使用子进程执行命令，但不捕获输出（让输出直接显示在控制台）
                    process = subprocess.Popen([run_good_path, config_file],
                                                stdout=subprocess.PIPE, 
                                                stderr=subprocess.PIPE, 
                                                bufsize=1,  # 行缓冲
                                                universal_newlines=True)  # 使用文本模式
            
                    # 发送成功响应
                    self.send_response(200)
                    self.send_header('Content-type', 'application/json')
                    self.end_headers()
                    self.wfile.write(json.dumps({'success': True}).encode())

                    # 实时读取并显示输出
                    def read_output(pipe, log_func):
                        for line in iter(pipe.readline, ''):
                            log_func(line.strip())
                        pipe.close()
            
                    # 创建线程来读取输出，避免阻塞
                    import threading
                    stdout_thread = threading.Thread(target=read_output, args=(process.stdout, logger.info))
                    stderr_thread = threading.Thread(target=read_output, args=(process.stderr, logger.error))
                    stdout_thread.daemon = True  # 设置为守护线程，主线程结束时自动结束
                    stderr_thread.daemon = True
                    stdout_thread.start()
                    stderr_thread.start()

                    # 等待进程完成
                    return_code = process.wait()
                    # 等待输出读取完成
                    stdout_thread.join()
                    stderr_thread.join()
                    logger.info(f"Download process completed with return code: {return_code}")

                
                    # 删除配置文件
                    if os.path.exists(config_file):
                        os.remove(config_file)
                        logger.info(f"Removed temporary config file: {config_file}")
                
                except Exception as e:
                    logger.error(f"Error executing download command: {str(e)}")
                    # 注意：响应已经发送，这里不能再发送错误响应
                    # 删除配置文件
                    if os.path.exists(config_file):
                        os.remove(config_file)
                
            except Exception as e:
                self.send_response(500)
                self.send_header('Content-type', 'application/json')
                self.end_headers()
                self.wfile.write(json.dumps({'success': False, 'error': str(e)}).encode())
            return


    
def is_port_available(port):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        try:
            s.bind(('localhost', port))
            return True
        except OSError:
            return False
        
# 启动服务器
def run_server(port=8080):
    # 检查端口是否可用，如果不可用则尝试其他端口
    original_port = port
    while not is_port_available(port) and port < original_port + 100:
        print(f"Port {port} is in use, trying port {port + 1}")
        port += 1
    
    if port >= original_port + 100:
        print(f"Could not find an available port in range {original_port}-{original_port + 99}")
        return

    # 读取 HTML 文件
    try:
        with open('config_generator.html', 'r', encoding='utf-8') as file:
            html_content = file.read()
        
        # 获取当前脚本的目录路径
        script_dir = os.path.dirname(os.path.abspath(__file__))
        
        import re
        # 1. 替换 mainDir 输入框的 value 属性
        pattern_dir = r'(<input[^>]*id="mainDir"[^>]*value=")([^"]*)(">)'
        html_content = re.sub(pattern_dir, lambda m: m.group(1) + script_dir.replace('\\', '\\\\') + m.group(3), html_content)
        
        # 2. 替换端口号 - 使用正则表达式查找 serverPort 变量定义
        pattern_port = r'(const\s+serverPort\s*=\s*)(\d+)'
        html_content = re.sub(pattern_port, lambda m: m.group(1) + str(port), html_content)
        
        # 写入修改后的内容
        with open('config_generator.html', 'w', encoding='utf-8') as file:
            file.write(html_content)
        
        print(f"Change the main_dir into {script_dir}")
        print(f"Change the port into {port}")
        handler = CORSHTTPRequestHandler
        print(f"Server running at http://localhost:{port}")
        # 启动浏览器
        webbrowser.open(f"http://localhost:{port}")
        with socketserver.TCPServer(("", port), handler) as httpd:
            httpd.serve_forever()
    except FileNotFoundError:
        print("Error: config_generator.html file not found")
        return
    except PermissionError:
        print("Error: Permission denied when accessing config_generator.html")
        return
    except Exception as e:
        print(f"Error processing HTML file: {str(e)}")
        return






if __name__ == "__main__":
    try:
        run_server()
    except KeyboardInterrupt:
        print("\nServer shutdown requested by user")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
    finally:
        print("Server has been shut down")

