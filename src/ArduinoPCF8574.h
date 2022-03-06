//
// Created by KingS on 2022/3/5.
//

#ifndef __ARDUINO_PCF8574_H
#define __ARDUINO_PCF8574_H

#include <Arduino.h>

class ArduinoPCF8574 {

public:
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

public:
    struct GPIO {
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
        static GPIO from(unsigned short value);

        /**
         * 将引脚状态转换成数值
         * @since 1.0.0
         */
        static unsigned short toValue(GPIO gpio);

    public:
        unsigned short toValue();

        String toString() const;

        bool operator[](unsigned short index) const;

        GPIO set(unsigned short index, bool value);
    };

public:
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
    static GPIO read(JUMP jump);

    /**
     * 写入当前变量
     * @param jump
     * @since 1.0.0
     * @see Wire#endTransmission
     */
    static uint8_t write(JUMP jump, GPIO gpio);

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
    GPIO read();

    uint8_t write(GPIO gpio);

    uint8_t write(unsigned short value);

private:
    JUMP mJump;
};


#endif //__ARDUINO_PCF8574_H
