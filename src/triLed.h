#include "Arduino.h"

class Color {
  private:
    float m_r;
    float m_g;
    float m_b;

  public:
    float r();
    float g();
    float b();

    void r(float val);
    void g(float val);
    void b(float val);

    Color();
    Color(float r, float g, float b);
};

class TriLED {
  private:
    Color m_color;
    float m_brightness;

    int m_rPin;
    int m_gPin;
    int m_bPin;

  public:
    TriLED(int rPin, int gPin, int bPin);
    TriLED(int rPin, int gPin, int bPin, Color color);

    void setBrightness(float val);
    void setColor(Color color);
    void setColor(Color color, float brightness);
    void writeColor();
};

float resetBound(float val);
