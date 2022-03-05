//
// Created by KingS on 2022/3/5.
//

#include "ArduinoPCF8574.h"

#include <Wire.h>

static ArduinoPCF8574 *sInstance = nullptr;

ArduinoPCF8574 *ArduinoPCF8574::getInstance() {
    if (sInstance == nullptr)
        sInstance = new ArduinoPCF8574();
    return sInstance;
}

ArduinoPCF8574::ArduinoPCF8574() : P0(false), P1(false), P2(false), P3(false), P4(false), P5(false), P6(false), P7(false) {}

void ArduinoPCF8574::setup() {
    Wire.begin();
}

uint8_t ArduinoPCF8574::read(ArduinoPCF8574::JUMP jump) {
    Wire.beginTransmission(jump);
    int value = Wire.read();
    P0 = (value & 0x01) == 1;
    P1 = ((value >> 1) & 0x01) == 1;
    P2 = ((value >> 2) & 0x01) == 1;
    P3 = ((value >> 3) & 0x01) == 1;
    P4 = ((value >> 4) & 0x01) == 1;
    P5 = ((value >> 5) & 0x01) == 1;
    P6 = ((value >> 6) & 0x01) == 1;
    P7 = ((value >> 7) & 0x01) == 1;
    return Wire.endTransmission();
}

uint8_t ArduinoPCF8574::write(JUMP jump) {
    return write(jump, P0, P1, P2, P3, P4, P5, P6, P7);
}

uint8_t ArduinoPCF8574::write(JUMP jump, bool p0, bool p1, bool p2, bool p3, bool p4, bool p5, bool p6, bool p7) {
    unsigned short value = p7 ? 1 : 0;
    value = (value << 1) | (p6 ? 1 : 0);
    value = (value << 1) | (p5 ? 1 : 0);
    value = (value << 1) | (p4 ? 1 : 0);
    value = (value << 1) | (p3 ? 1 : 0);
    value = (value << 1) | (p2 ? 1 : 0);
    value = (value << 1) | (p1 ? 1 : 0);
    value = (value << 1) | (p0 ? 1 : 0);
    return write(jump, value);
}

uint8_t ArduinoPCF8574::write(JUMP jump, unsigned short value) {
    Serial.printf("[p] jump:%d value:%d\n", jump, value);
    Wire.beginTransmission(jump);
    Wire.write(value);
    return Wire.endTransmission();
}

