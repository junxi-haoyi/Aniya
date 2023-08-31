# Aniya Watch💖

注：此项目是参考[Monica](https://github.com/Forairaaaaa/monica)根据自己的想法进行一些更改和添加，更多的是学习。在此特别感谢[@Forairaaaaa](https://oshwhub.com/eedadada)
![](https://aniya.oss-cn-shanghai.aliyuncs.com/case%20v82.png)

硬件开源地址：

**制作不易，别忘了点一个star**🥰🥰🥰🥰🥰🥰
## 手表功能
- 蓝牙HID：及开启后可以将手表识别为键盘，在SD卡里面可以存一些密码或者其他东西，在屏幕上点击一下即可在电脑或者手机端输入文本
- 计步器：BMI270内部硬件计步
- 可以调节屏幕亮度
- 自定义表盘
- 查看天气信息
- 查看时间，日期


## 屏幕型号
该项目代码适配了两个屏幕，一个是1.78寸AMOLED，另一个是1.69寸 ST7789 LCD屏幕。

AMOLED屏幕显示效果好、分辨率高、低功耗，但是界面会有少许的卡顿，但是还能接受。

LCD屏幕功耗高、分辨率低、但是帧数可以稳定在50 FPS左右，界面会丝滑很多。

代码默认适配了AMOLED，如果选择LCD还需要更改很多内容，但是LCD的驱动已经写好了，并且和LVGL对接也没有问题。
##  硬件
- 屏幕：1.78寸AMOLED，使用QSPI进行通讯，QSPI是具有四根数据线的SPI，速度就会比单线的快,某宝搜达沃即可
- 主控：ESP32-S3 8M PSRAM,主频最高240M，并且外置32M华邦FLASH的闪存颗粒
- BMI270：6轴陀螺仪
- PCF8563T：RTC日历，断电计时
- AXP2101：电源管理芯片
- BMP280: 气压传感器
- 一个麦克风
- 一个Type-C口（本次设计中失败之处，因为type-c会占用大量的空间，导致PCB和3D建模都不好绘制）
**原理图**
![](https://aniya.oss-cn-shanghai.aliyuncs.com/_Aniya.png)
**PCB**
**重点**：
- TF卡槽的switch用于检测TF卡是否插入，他和VDD3V3相连，千万不要接地
- AXP2101的DCDC1稳定输出3.3V，所以也就不存在定制芯片的原因，但是这款芯片价格不菲，我是买这家的<a href="https://m.tb.cn/h.53y0l3c?tk=C29GdCWJpgx" target="_blank">AXP2101</a>
- ![](https://aniya.oss-cn-shanghai.aliyuncs.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-08-29%20193009.png)
![](https://aniya.oss-cn-shanghai.aliyuncs.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-08-29%20181106.png)


本次PCB设计为4层，3层信号层以及一个完整的地平面，布线虽然不咋地，但是此次设计已经是我目前绘制过最难的一次PCB
## 软件
- 开发环境：WSL2 Ubuntu22.04
- 开发工具：VScode + Squareline Studio（lvgl官方出的可以图形化生成代码的软件，前提是要有一份移植好的LVGL的工程）
- 开发框架: IDF5.02
- 语言：C/C++
- 图形驱动：<a href="https://github.com/lovyan03/LovyanGFX" target="_blank">lovyanGFX</a>高效便捷的图形驱动，毕竟自己写估计。。。🤯
- 图形库：LVGL，众所周知，LVGL的难点在于移植，小伙伴们如果解决了移植问题，那基本克服了50%的困难，另外50%是随机的🤣

其实如果使用st或者其他arm的芯片开发lvgl的项目是比较头疼的，光是将文件添加到项目工程里面就搞得头大，而且芯片的RAM和flash不足，如果外扩FLASH或者SDRAM的话资料又比较的少（毕竟我没去找），ESP32的价格和st或者gd的芯片接近，但是性能和功能确实的好几倍。ESP32使用CMake来管理项目，移植更加方便，可以真正的做到AIOT，万物互联，而且ESP32在github的活跃程度还是挺高的。

但是ESP32的入门并不友好，当然有我们熟知的Arduino或者Micropython，其实这两个种环境都背离了原理，面向初学者，使用者不需要知道原理会调用一些API即可，而且这些高度抽象化的封装会导致单片机性能的下降，图形化界面卡顿。Micropython目前来说更像一种玩具，只适合在高性能单片机上运行。IDF更加面向底层，面向原理，执行效率快，功能最齐全，但也更难。

当然工具不分贵贱，大家需要根据自己的实际情况选择适合开发环境🫡
![](https://aniya.oss-cn-shanghai.aliyuncs.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-08-29%20190557.png)

## IIC地址问题
IIC地址因为存在最后一位是读（1）还是写（0），而且在函数里面填地址的时候，到底是写添加读写位的地址，还是填原地址

在这里说明一下，ESP32 IDF是需要填写原地址（不加读写位），STM32的IIC需要添加读写位。

## 蓝牙键盘功能说明
- 不建议在不插电源的情况下开启蓝牙功能，因为开启蓝牙后，会明显感觉（物理）到芯片发烫，虽然叫BLE（低功耗蓝牙），咱也不懂
- 开启蓝牙功能需要在menuconfig里面设置一下，才能开启蓝牙功能

##  3D建模
本次使用的是Fusion360来绘制该手表的外壳，不得不感叹，我从B站大学毕业，自己画的可能比较粗略，仅供参考。
![](https://aniya.oss-cn-shanghai.aliyuncs.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-08-29%20191605.png)

本次项目耗时将近两个月甚至更多，光是把屏幕驱动起来就花了将近半个月，代码目前还在编写阶段，但是已经有了基本的启动界面
![](https://aniya.oss-cn-shanghai.aliyuncs.com/1693309733813.jpg)

## 软件流程图
![](https://aniya.oss-cn-shanghai.aliyuncs.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-08-29%20212308.png)

**main 文件夹**

![](https://aniya.oss-cn-shanghai.aliyuncs.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-08-29%20212656.png)

- MYUI：本文件的UI部分
- hal：硬件抽象层， 参考[Monica](https://github.com/Forairaaaaa/monica)
- squareline：Squareline Studio生成的代码，用于测试
- main.cpp:该项目是由C++编写的

**components 文件夹**

![](https://aniya.oss-cn-shanghai.aliyuncs.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-08-29%20213323.png)

- LovyanGFX:一个高效的图形库
- aniya_ble:蓝牙HID驱动代码
- aniya_wifi:WIFI驱动代码
- lvgl：lvgl源码

## App的创建与删除
![](https://aniya.oss-cn-shanghai.aliyuncs.com/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE%202023-08-29%20220427.png)
其实就是使用了lvgl的各个组件的回调函数来管理APP的生命周期，至于Android的那一套App管理思想，不是那么容易实现，MYUI下的APP各自属性都不一样，无法做到Android那一套的统一管理



## 相关链接
- Monica : <a href="https://github.com/Forairaaaaa/monica.git">Forairaaaaa/monica</a>
- emoji表情壁纸网站: <a hred="https://www.freepik.com/">emoji</a>
- Bit map字体网站: <a href="https://www.dafont.com/bitmap.php">Bit map</a>
- ESP32-IDF: <a href="https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/get-started/index.html">ESP-TDF</a>
- LovyanGFX : <a href="https://github.com/lovyan03/LovyanGFX.git">lovyan03/LovyanGFX</a>
- ArduinoJson : <a href="https://github.com/bblanchon/ArduinoJson.git">bblanchon/ArduinoJson</a>