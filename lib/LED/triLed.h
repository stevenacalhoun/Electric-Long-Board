#include "Arduino.h"
#include "../Color/color.h"

#pragma once

// Tri Color LED
class TriLED {
  private:
    Color m_currentColor;
    Color m_targetColor;
    Color m_previousColor;

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
    TriLED(int rPin, int gPin, int bPin, Color color, float transitionSpeed);

    Color getCurrentColor();
    void setCurrentColor(Color color);

    Color getPreviousColor();
    void setPreviousColor(Color previousColor);

    Color getTargetColor();
    void setTargetColor(Color targetColor);

    float getTransitionSpeed();
    void setTransitionSpeed(float transitionSpeed);

    void moveToTarget();

    void turnOn();
    void turnOff();
    void toggle();
};

// Reset value to 0-255
float resetBound(float val);
