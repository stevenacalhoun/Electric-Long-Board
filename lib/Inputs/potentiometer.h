#include "Arduino.h"
#pragma once

class Potentiometer {
  private:
    int m_pin;

  public:
    Potentiometer(int pin);

    float read();
};
