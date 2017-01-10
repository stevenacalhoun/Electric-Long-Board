#include "Arduino.h"
#pragma once

class Button {
  private:
    // Statuses
    int m_pin;
    int m_state;
    int m_lastState = LOW;
    bool m_toggled = false;

    // Constants for debounce
    unsigned long m_lastDebounceTime = 0;
    unsigned long m_debounceDelay = 50;

  public:
    Button(int pin);

    void update();
    int read();
    bool hasToggled();
};
