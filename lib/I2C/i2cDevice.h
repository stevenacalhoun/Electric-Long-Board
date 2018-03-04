#include <Arduino.h>

#pragma once

class I2CDevice {
  public:
    I2CDevice();

    virtual void receiveEvent(String message) = 0;
    virtual String requestEvent() = 0;
};

