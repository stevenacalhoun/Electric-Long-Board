#include "Arduino.h"
#include "../Color/colorRGB.h"

#pragma once

// Tri Color LED
class TriLED {
  private:
    ColorRGB m_currentColor;
    ColorRGB m_targetColor;
    ColorRGB m_previousColor;

    int m_rPin;
    int m_gPin;
    int m_bPin;
    int m_onStatus = HIGH;
    float m_transitionSpeed;

    float m_dR;
    float m_dG;
    float m_dB;

    void writeLEDValues();

  public:
    TriLED();
    TriLED(int rPin, int gPin, int bPin, ColorRGB color, float transitionSpeed);

    ColorRGB getCurrentColor();
    void setCurrentColor(ColorRGB color);

    ColorRGB getPreviousColor();
    void setPreviousColor(ColorRGB previousColor);

    ColorRGB getTargetColor();
    void setTargetColor(ColorRGB targetColor);

    float getTransitionSpeed();
    void setTransitionSpeed(float transitionSpeed);

    void moveToTarget();

    bool getOnState();
    void turnOn();
    void turnOff();
    void toggle();
};

// Reset value to 0-255
float resetBound(float val);
