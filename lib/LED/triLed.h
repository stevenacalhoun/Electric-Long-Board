#include "Arduino.h"
#pragma once

#define YELLOW Color(255,112,0)
#define RED Color(255,0,0)
#define GREEN Color(0,255,0)
#define BLUE Color(0,0,255)

class Color {
  private:
    float m_r;
    float m_g;
    float m_b;

  public:
    Color();
    Color(float r, float g, float b);

    float r();
    float g();
    float b();

    void r(float val);
    void g(float val);
    void b(float val);
};

class TriLED {
  private:
    Color m_color;
    float m_brightness;

    int m_rPin;
    int m_gPin;
    int m_bPin;

    int m_onOffStatus = HIGH;

  public:
    TriLED(int rPin, int gPin, int bPin);
    TriLED(int rPin, int gPin, int bPin, Color color);

    void setBrightness(float val);
    void setColor(Color color);
    void setColor(Color color, float brightness);
    void writeColor();


    void turnOn();
    void turnOff();
    void toggle();
};

float resetBound(float val);
