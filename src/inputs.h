#include "Arduino.h"

class Button {
  private:
    int m_pin;

  public:
    Button(int pin);

    int read();
};

class Potentiometer {
  private:
    int m_pin;

  public:
    Potentiometer(int pin);

    float read();
};
