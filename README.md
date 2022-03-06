# Arduino PCF8574

## 说明

一个Arduino的`PCF8574`的I/O拓展板库，目前测试支持下面几种板子。支持完全串联控制，也就是支持到64个IO接口。

![board](images/images-01.png)

> #### ⚠️ 注意：
>
> 如果想使用PCF8574作为输入，那么此接口必须为高电平，也就是将IO设置为1，否者无法读取状态。
> 
> 这个是我写一个的PCF8574作为输入按钮的仓库：[ArduinoPCF8574Button](https://github.com/arduine/ArduinoPCF8574Button.git)

## 导入

#### PlatformIO

```ini
; Library options
lib_deps =
    https://github.com/arduine/ArduinoPCF8574.git#main
```

#### ArduinoIDE

```c++
// TODO
```

## 使用

1. 增加头文件导入：

```c++
#include <ArduinoPCF8574.h>
```

2. 初始化

```c++
void setup() {
    ArduinoPCF8574::setup(); // <-- 初始化
}

void onYouFunction() {
    // 读取状态
    auto gpio = ArduinoPCF8574::read(ArduinoPCF8574::J32);
    Serial.printf("JUMP 32 "
                  "GPIO P0:%d, P1:%d, P2:%d,   P3:%d,   P4:%d,   P5:%d,   P6:%d,   P7:%d\n",
                  gpio.P0, gpio.P1, gpio.P2, gpio.P3, gpio.P4, gpio.P5, gpio.P6, gpio.P7);
    
    // 设置状态
    gpio.P5 = true;
    ArduinoPCF8574::write(ArduinoPCF8574::J32, gpio);
}
```

## 跳线

```c++
/**
 * +----+---+---+---+    +----+---+---+---+    +----+---+---+---+    +----+---+---+---+
 * |    | V | - | G |    |    | V | - | G |    |    | V | - | G |    |    | V | - | G |
 * +----+---+---+---+    +----+---+---+---+    +----+---+---+---+    +----+---+---+---+
 * | A2 |   | X | X |    | A2 |   | X | X |    | A2 |   | X | X |    | A2 |   | X | X |
 * +----+---+---+---+    +----+---+---+---+    +----+---+---+---+    +----+---+---+---+
 * | A1 |   | X | X |    | A1 |   | X | X |    | A1 | X | X |   |    | A1 | X | X |   |
 * +----+---+---+---+    +----+---+---+---+    +----+---+---+---+    +----+---+---+---+
 * | A0 |   | X | X |    | A0 | X | X |   |    | A0 |   | X | X |    | A0 | X | X |   |
 * +----+---+---+---+    +----+---+---+---+    +----+---+---+---+    +----+---+---+---+
 */
J32=32,                  J33=33,               J34=34,               J35=35,

/**
 * +----+---+---+---+    +----+---+---+---+    +----+---+---+---+    +----+---+---+---+
 * |    | V | - | G |    |    | V | - | G |    |    | V | - | G |    |    | V | - | G |
 * +----+---+---+---+    +----+---+---+---+    +----+---+---+---+    +----+---+---+---+
 * | A2 | X | X |   |    | A2 | X | X |   |    | A2 | X | X |   |    | A2 | X | X |   |
 * +----+---+---+---+    +----+---+---+---+    +----+---+---+---+    +----+---+---+---+
 * | A1 |   | X | X |    | A1 |   | X | X |    | A1 | X | X |   |    | A1 | X | X |   |
 * +----+---+---+---+    +----+---+---+---+    +----+---+---+---+    +----+---+---+---+
 * | A0 |   | X | X |    | A0 | X | X |   |    | A0 |   | X | X |    | A0 | X | X |   |
 * +----+---+---+---+    +----+---+---+---+    +----+---+---+---+    +----+---+---+---+
 */
J36=36,                  J37=37,               J38=38,               J39=39
```

## LICENSE

```text
                                 Apache License
                           Version 2.0, January 2004
                        http://www.apache.org/licenses/

   TERMS AND CONDITIONS FOR USE, REPRODUCTION, AND DISTRIBUTION
```