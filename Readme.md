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

因为Windows硬盘分区的限制，路径访问无法越过不同的盘符，所以推荐直接粘贴路径

```bash
cd bin_Win
python3.exe .\main.py
```

---

:exclamation: 请注意，因为作者关于网络通信的知识有限，并没有对端口的占用做自动调整，所以有可能在运行后浏览器内会出现该端口忙的提示

可以点击重试，或者关闭例如代理软件等可能会占用10000端口的应用

---

:exclamation:使用时如果改变了main_dir，那么请确保当前目录下存在thirdparty文件夹以支持下载的完成

​	 可以把thirdparty文件夹移动到指定的文件夹下，推荐直接修改main_dir路径为bin_Win/bin_Linux的路径

---

关于默认路径的设置，请参见`config_generator.html`内的注释

```html
<input type="text" id="mainDir" value="/home/sheep/文档/GOOD_GUI/bin_Linux">
```

找到这行代码，修改value属性值，即可更改默认启动路径

---

:sparkles:添加了从地图上选取站点进行下载的功能，但是因为网络环境的问题，openstreet的底图是无法使用的，所以作者只能用天地图的底图代替

天地图则是需要提供具体的token才能调用地图服务的，所以如果需要使用这个功能，需要使用者自行到天地图官网申请一个账号，然后填入自己的token来使用（`stations.html`文件内）

```javascript
<script type="text/javascript" src="http://api.tianditu.gov.cn/api?v=4.0&tk=在此替换为自己的天地图token"></script>
```

从地图中选取站点的示意图：

<img src="./.assets/selectfrommap.png" alt="selectFromMap" style="zoom:75%;" />

选取后点击`保存为site_obs.list`即可覆盖原本的site_obs.list文件

:exclamation:显示的站点是从SINEX文件中提取的，所以尽管显示了这些站点，并不代表都能从当前选取的服务器中下载到

如果需要添加一些自定义的站点，可以在`./thirdparty/station_coordinates.js`文件中按照格式添加站点信息即可

```js
["AB09", -168.062138889, 65.614972222] // "station_ID", lon(deg), lat(deg)
```

---

添加了一个名为Simplify Directory Structure的Checkbox

选定后可以简化obs和nav的文件路径，但因为是暴力移动的，所以忽略了日期这些信息

简化前：

```
./obs
└── 2024
    └── 001
        └── MGEX
            └── daily
                ├── abmf0010.24o
                └── ABMF00GLP_R_20240010000_01D_30S_MO.rnx
./nav
└── 2024
    └── 001
        ├── BRDC00IGS_R_20240010000_01D_MN.rnx
        └── brdm0010.24p
```

简化后：

```
./obs
├── abmf0010.24o
└── ABMF00GLP_R_20240010000_01D_30S_MO.rnx
./nav
├── BRDC00IGS_R_20240010000_01D_MN.rnx
└── brdm0010.24p
```

---

:rocket:***后期改进想法**

1. wget本身对多线程下载的支持并不好，后续或许可以更改下载引擎为Aria2，不过这个的工作量比较大
2. ...

:heart:希望各位能够提出在使用过程中遇到的bug，同时也欢迎各位贡献自己的想法到repo中

:e-mail: : laishipei1212@163.com
