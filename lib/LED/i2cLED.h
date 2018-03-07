#include <Arduino.h>

#include "../LED/triLED.h"
#include "../Color/colorHSV.h"
#include "../Color/colorRGB.h"
#include "../I2C/i2cDevice.h"
#include "../I2C/i2cBus.h"

#pragma once

class I2CLED : public I2CDevice  {
  public:
    I2CLED();
    I2CLED(int rPin, int gPin, int bPin, ColorHSV startColor, I2CBus* bus);

    void receiveEvent(String message);
    String requestEvent();

    void parseI2CColor(String message);

    void update();

  private:
    TriLED m_led;
    ColorHSV m_currentColor;

    void updateLED(ColorRGB color);

    String m_currentRequest;
};
