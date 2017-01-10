#include "button.h"

Button::Button(int pin) {
  m_pin = pin;
  pinMode(m_pin, INPUT);
}

// Debounce update, run every loop
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
  if ((reading == 1) && (reading != m_lastState)) {
    m_toggled = true;
  }

  m_lastState = reading;
}

// Read current state
int Button::read() {
  return m_state;
}

// Check if button has been toggled and reset status
bool Button::hasToggled() {
  bool retVal = m_toggled;
  m_toggled = false;
  return retVal;
}
