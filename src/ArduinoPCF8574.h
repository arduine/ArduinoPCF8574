//
// Created by KingS on 2022/3/5.
//

#ifndef __ARDUINO_PCF8574_H
#define __ARDUINO_PCF8574_H

#include <Arduino.h>

class ArduinoPCF8574 {
public:
    static ArduinoPCF8574 *getInstance();

private:
    ArduinoPCF8574();

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
    /**
     * 初始化程序
     * @since 1.0.0
     */
    void setup();

    /**
     * 读取当前的状态，存放在变量中
     * @param jump
     * @since 1.0.0
     * @see Wire#endTransmission
     */
    uint8_t read(JUMP jump);

    /**
     * 写入当前变量
     * @param jump
     * @since 1.0.0
     * @see Wire#endTransmission
     */
    uint8_t write(JUMP jump);

    /**
     * 写入当前变量
     * @param jump
     * @param value 注意总数不要超过255
     * @since 1.0.0
     * @see Wire#endTransmission
     */
    uint8_t write(JUMP jump, unsigned short value);

    /**
     * 写入当前变量
     * @param jump
     * @param p0
     * @param p1
     * @param p2
     * @param p3
     * @param p4
     * @param p5
     * @param p6
     * @param p7
     * @since 1.0.0
     * @see Wire#endTransmission
     */
    uint8_t write(JUMP jump, bool p0 = false, bool p1 = false, bool p2 = false, bool p3 = false, bool p4 = false, bool p5 = false, bool p6 = false, bool p7 = false);

public:
    bool P0, P1, P2, P3, P4, P5, P6, P7;

};


#endif //__ARDUINO_PCF8574_H
