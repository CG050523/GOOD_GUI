## GOOD_GUI

基于GOOD, version 3.1 (https://github.com/zhouforme0318/GAMPII-GOOD) 开发的图形界面

使用Qt 5.15.3进行图形化版本的开发

Linux编译，请先安装基本的Qt组件，Qtcore...

simple as usual.

```bash
mkdir build
cd build && qmake ../src/Hello.pro
make
./Hello
```

> Ver_1.0

实现了基础功能，同时使用多线程create临时创建的方式让下载和UI更新在不同线程中进行

下一阶段目标：为软件添加配置文件，这样有些目录的配置就不用每次启动都重复配置
