## GOOD_GUI

基于GOOD, version 3.1（https://github.com/zhouforme0318/GAMPII-GOOD）开发的图形界面

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

实现了基础功能，但在运行时还会出现界面无法响应的问题，后续打算用多线程的方式解决
