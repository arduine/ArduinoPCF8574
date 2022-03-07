//
// Created by KingS on 2022/3/5.
//

#ifndef __ARDUINO_PCF8574_H
#define __ARDUINO_PCF8574_H

#include <Arduino.h>

/**
 * 一个Arduino控制PCF8574芯片的库
 * @author sollyu
 * @see https://github.com/arduine/ArduinoPCF8574
 */
class ArduinoPCF8574 {

public:
    /**
     * 跳线配置列表
     * @since 1.0.0
     */
    enum JUMP {
        // @formatter:off
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
        // @formatter:on
    };

    /**
     * 接口定义
     * @since 1.0.2
     */
    enum PIN {
        P0 = 0, P1 = 1, P2 = 2, P3 = 3, P4 = 4, P5 = 5, P6 = 6, P7 = 7
    };

public:
    /**
     * 当前接口状态
     * @since 1.0.0
     */
    struct State {
        bool P0 = false;
        bool P1 = false;
        bool P2 = false;
        bool P3 = false;
        bool P4 = false;
        bool P5 = false;
        bool P6 = false;
        bool P7 = false;

    public:
        /**
         * 从数值中分析引脚状态
         * @since 1.0.0
         */
        static State from(unsigned short value);

        /**
         * 将引脚状态转换成数值
         * @since 1.0.0
         */
        static unsigned short toValue(State state);

    public:
        unsigned short toValue();

        String toString() const;

        /**
         * 使用数组的方式读取引脚的状态
         * @param pin 引脚
         * @since 1.0.2
         */
        bool operator[](const PIN &pin) const;

        /**
         * 设置引脚的状态
         * @param pin   引脚接口
         * @param value 状态
         * @since 1.0.2
         */
        State set(const PIN &pin, bool value);
    };

public:
    /**
     * @param jump 当前跳线位置
     * @since 1.0.1
     */
    explicit ArduinoPCF8574(JUMP jump);

public:
    /**
     * 初始化程序
     * @since 1.0.0
     */
    static void setup();

    /**
     * 读取当前的状态，存放在变量中
     * @param jump
     * @since 1.0.0
     * @see Wire#endTransmission
     */
    static State read(JUMP jump);

    /**
     * 写入当前变量
     * @param jump
     * @since 1.0.0
     * @see Wire#endTransmission
     */
    static uint8_t write(JUMP jump, State gpio);

    /**
     * 写入当前变量
     * @param jump
     * @param value 注意总数不要超过255
     * @since 1.0.0
     * @see Wire#endTransmission
     */
    static uint8_t write(JUMP jump, unsigned short value);

    /**
     * 是否已经初始化
     * @since 1.0.0
     */
    static bool isInited();

public:
    /**
     * 读取状态
     * @since 1.0.1
     */
    State read();

    /**
     * 设置接口状态
     * @param state 接口状态
     * @since 1.0.1
     */
    uint8_t write(State state);

    /**
     * 写入数据
     * @param value 手动配置接口状态
     * @since 1.0.1
     */
    uint8_t write(unsigned short value);

private:
    JUMP mJump;
};


#endif //__ARDUINO_PCF8574_H
