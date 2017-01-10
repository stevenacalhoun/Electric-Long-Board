#include "potentiometer.h"

Potentiometer::Potentiometer(int pin) {
  m_pin = pin;
  pinMode(m_pin, INPUT);
}

float Potentiometer::read() {
  return analogRead(m_pin);
}
