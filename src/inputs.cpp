#include "inputs.h"

Button::Button(int pin) {
  m_pin = pin;
  pinMode(m_pin, INPUT);
}

int Button::read() {
  return digitalRead(m_pin);
}

Potentiometer::Potentiometer(int pin) {
  m_pin = pin;
  pinMode(m_pin, INPUT);
}

float Potentiometer::read() {
  return analogRead(m_pin);
}
