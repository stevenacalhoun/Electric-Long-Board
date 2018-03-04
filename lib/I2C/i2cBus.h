#include <Arduino.h>

#include "i2cDevice.h"

#pragma once

class I2CBus {
  public:
    I2CBus();

    void registerDevice(int address, I2CDevice* device);

    void write(String message);
};

void receiveEvent(int messageCount);
void requestEvent();
