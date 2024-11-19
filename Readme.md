## GOOD_GUI

基于GOOD, version 3.1 https://github.com/zhouforme0318/GAMPII-GOOD
开发的图形界面

使用Qt 5.15.3进行图形化版本的开发

理论上是可以在Win平台进行编译的，但添加的yaml-cpp在进行release时总是报错

后续有时间在优化

Linux编译，请先安装基本的Qt组件，Qtcore...

simple as usual.

```bash
mkdir build
cd build && qmake ../src/Hello.pro
make -j8
./Hello
```

