#include "Arduino.h"
#pragma once

class Button {
  private:
    int m_pin;
    int m_state;
    int m_lastState = LOW;

    unsigned long m_lastDebounceTime = 0;
    unsigned long m_debounceDelay = 50;

  public:
    Button(int pin);

    void update();
    int read();
};
