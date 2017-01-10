#include "button.h"

Button::Button(int pin) {
  m_pin = pin;
  pinMode(m_pin, INPUT);
}

void Button::update() {
  int reading = digitalRead(m_pin);
  if (reading != m_lastState) {
    m_lastDebounceTime = millis();
  }

  if ((millis() - m_lastDebounceTime) > m_debounceDelay) {
    if (reading != m_state) {
      m_state = reading;
    }
  }
  m_lastState = reading;
}

int Button::read() {
  return m_state;
}
