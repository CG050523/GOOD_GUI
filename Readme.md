## GOOD_GUI

基于GOOD, version 3.1 (https://github.com/zhouforme0318/GAMPII-GOOD) 开发的图形界面

~~使用Qt 5.15.3进行图形化版本的开发~~

~~Linux编译，请先安装基本的Qt组件，Qtcore...~~

~~simple as usual.~~

> ~~Ver_1.0~~

~~实现了基础功能，同时使用多线程create临时创建的方式让下载和UI更新在不同线程中进行~~

~~下一阶段目标：为软件添加配置文件，这样有些目录的配置就不用每次启动都重复配置~~

### :sparkles:Brand-New Version

考虑到原本的GOOD软件大量使用终端来调用wget进行下载，想把GUI强行嵌入其中不现实，最方便的形式还是作为一个配置生成器来实现

同时考虑到Qt需要静态编译才能摆脱运行库的限制，所以作者打算采用html+js的形式来写一个配置生成器，用python做后端响应

这样绝大部分使用者都能避免安装第三方运行库，同时也不用考虑终端信息显示的丢失

---

**🛠️Run Under Linux**

因为绝大部分Linux发行版都内置了python解释器，所以运行方法很简单

```bash
cd bin_Linux
python3 ./main.py
```

---

**🛠️ Run Under Win**

为了尽可能减少环境配置的问题，所以作者在win的文件夹内置了python解释器，无需配置python的环境变量

只需要双击`.bat`批处理文件就能自动打开配置器

如果使用者想使用自己环境变量里配置的，使用下列代码即可

```bash
cd bin_Win
python3.exe .\main.py
```

---

:exclamation: ~~请注意，因为作者关于网络通信的知识有限，并没有对端口的占用做自动调整，所以有可能在运行后浏览器内会出现该端口忙的提示~~

~~可以点击重试，或者关闭例如代理软件等可能会占用8080端口的应用~~

目前已经添加了端口占用检测和自动修改端口的功能，初步实现，并不是一个足够稳健的策略

---

:exclamation:使用时如果改变了main_dir，那么请确保当前目录下存在thirdparty文件夹以支持下载的完成

​	 可以把thirdparty文件夹移动到指定的文件夹下，推荐直接移动整个bin_Linux/bin_Win文件夹到目标目录

---

关于默认路径的设置，请参见`config_generator.html`内的注释

```html
<input type="text" id="mainDir" value="/home/sheep/文档/GOOD_GUI/bin_Linux">
```

作者现在修改了main脚本的内容，现在启动时脚本会自动获取绝对路径并对上面的value属性值进行替换

---

**:rocket:后期改进想法**

1. wget本身对多线程下载的支持并不好，后续或许可以更改下载引擎为Aria2，不过这个的工作量比较大
2. ...

:heart:希望各位能够提出在使用过程中遇到的bug，同时也欢迎各位贡献自己的想法到repo中

:e-mail: : laishipei1212@163.com
