#include "Arduino.h"
#include <color.h>

#pragma once

// Common colors
#define YELLOW Color(255,112,0)
#define RED Color(255,0,0)
#define GREEN Color(0,255,0)
#define BLUE Color(0,0,255)

// Tri Color LED
class TriLED {
  private:
    // Color and brightness
    Color m_color;
    float m_brightness;

    // Pin for each color channel
    int m_rPin;
    int m_gPin;
    int m_bPin;

    // On/off
    int m_onStatus = HIGH;

    // Write to pins
    void updateLED();
    void setPins(int rPin, int gPin, int bPin);

  public:
    TriLED(int rPin, int gPin, int bPin);
    TriLED(int rPin, int gPin, int bPin, Color color);
    TriLED(int rPin, int gPin, int bPin, Color color, float brightness);

    void setBrightness(float val);
    void setColor(Color color);
    void setColor(Color color, float brightness);

    void turnOn();
    void turnOff();
    void toggle();
};

// Reset value to 0-255
float resetBound(float val);
