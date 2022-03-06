//
// Created by KingS on 2022/3/5.
//

#include "ArduinoPCF8574.h"

#include <Wire.h>

static bool sArduinoPCF8574IsInited = false;

ArduinoPCF8574::ArduinoPCF8574(ArduinoPCF8574::JUMP jump) : mJump(jump) {
}

void ArduinoPCF8574::setup() {
    if (sArduinoPCF8574IsInited)
        return;

    Wire.begin();
    sArduinoPCF8574IsInited = true;
}

ArduinoPCF8574::GPIO ArduinoPCF8574::read(ArduinoPCF8574::JUMP jump) {
    Wire.beginTransmission(jump);
    Wire.requestFrom((uint8_t) jump, (uint8_t) 1);
    unsigned short value = Wire.read();
    Wire.endTransmission();
    return GPIO::from(value);
}

uint8_t ArduinoPCF8574::write(JUMP jump, GPIO gpio) {
    return write(jump, gpio.toValue());
}

uint8_t ArduinoPCF8574::write(JUMP jump, unsigned short value) {
    Wire.beginTransmission(jump);
    Wire.write((uint8_t) value);
    return Wire.endTransmission();
}

bool ArduinoPCF8574::isInited() {
    return sArduinoPCF8574IsInited;
}

ArduinoPCF8574::GPIO ArduinoPCF8574::read() {
    return ArduinoPCF8574::read(mJump);
}

uint8_t ArduinoPCF8574::write(ArduinoPCF8574::GPIO gpio) {
    return ArduinoPCF8574::write(mJump, gpio);
}

uint8_t ArduinoPCF8574::write(unsigned short value) {
    return ArduinoPCF8574::write(mJump, value);
}

ArduinoPCF8574::GPIO ArduinoPCF8574::GPIO::from(unsigned short value) {
    auto gpio = ArduinoPCF8574::GPIO();
    gpio.P0 = (value & 0x01) == 1;
    gpio.P1 = ((value >> 1) & 0x01) == 1;
    gpio.P2 = ((value >> 2) & 0x01) == 1;
    gpio.P3 = ((value >> 3) & 0x01) == 1;
    gpio.P4 = ((value >> 4) & 0x01) == 1;
    gpio.P5 = ((value >> 5) & 0x01) == 1;
    gpio.P6 = ((value >> 6) & 0x01) == 1;
    gpio.P7 = ((value >> 7) & 0x01) == 1;
    return gpio;
}

unsigned short ArduinoPCF8574::GPIO::toValue(ArduinoPCF8574::GPIO gpio) {
    unsigned short value = gpio.P7 ? 1 : 0;
    value = (value << 1) + (gpio.P6 ? 1 : 0);
    value = (value << 1) + (gpio.P5 ? 1 : 0);
    value = (value << 1) + (gpio.P4 ? 1 : 0);
    value = (value << 1) + (gpio.P3 ? 1 : 0);
    value = (value << 1) + (gpio.P2 ? 1 : 0);
    value = (value << 1) + (gpio.P1 ? 1 : 0);
    value = (value << 1) + (gpio.P0 ? 1 : 0);
    return value;
}

unsigned short ArduinoPCF8574::GPIO::toValue() {
    return ArduinoPCF8574::GPIO::toValue(*this);
}

String ArduinoPCF8574::GPIO::toString() const {
    return String() +
           "P0=" + this->P0 + ", " +
           "P1=" + this->P1 + ", " +
           "P2=" + this->P2 + ", " +
           "P3=" + this->P3 + ", " +
           "P4=" + this->P4 + ", " +
           "P5=" + this->P5 + ", " +
           "P6=" + this->P6 + ", " +
           "P7=" + this->P7;
}

bool ArduinoPCF8574::GPIO::operator[](unsigned short index) const {
    switch (index) {
        case 0:
            return this->P0;
        case 1:
            return this->P1;
        case 2:
            return this->P2;
        case 3:
            return this->P3;
        case 4:
            return this->P4;
        case 5:
            return this->P5;
        case 6:
            return this->P6;
        case 7:
            return this->P7;
        default:
            return false;
    }
}

ArduinoPCF8574::GPIO ArduinoPCF8574::GPIO::set(unsigned short index, bool value) {
    switch (index) {
        case 0:
            this->P0 = value;
            break;
        case 1:
            this->P1 = value;
            break;
        case 2:
            this->P2 = value;
            break;
        case 3:
            this->P3 = value;
            break;
        case 4:
            this->P4 = value;
            break;
        case 5:
            this->P5 = value;
            break;
        case 6:
            this->P6 = value;
            break;
        case 7:
            this->P7 = value;
            break;
        default:
            break;
    }
    return *this;
}
