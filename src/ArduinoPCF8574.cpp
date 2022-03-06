//
// Created by KingS on 2022/3/5.
//

#include "ArduinoPCF8574.h"

#include <Wire.h>

static bool sArduinoPCF8574IsInited = false;

ArduinoPCF8574::ArduinoPCF8574() = default;

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
    Wire.write(value);
    return Wire.endTransmission();
}

bool ArduinoPCF8574::isInited() {
    return sArduinoPCF8574IsInited;
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
