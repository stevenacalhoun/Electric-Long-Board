#include <Arduino.h>

#include "../LED/triLED.h"
#include "../Color/color.h"
#include "../I2C/i2cDevice.h"
#include "../I2C/i2cBus.h"

#pragma once

class I2CLED : public I2CDevice  {
  public:
    I2CLED();
    I2CLED(int rPin, int gPin, int bPin, Color startColor, I2CBus* bus);

    void receiveEvent(String message);
    String requestEvent();

    void parseI2CColor(String message);

    void update();

  private:
    TriLED led;
    Color m_currentColor;

    String m_currentRequest;
};
