#include "triLed.h"

TriLED::TriLED(int rPin, int gPin, int bPin) {
  TriLED(rPin, gPin, bPin, Color(), 1);
}

TriLED::TriLED(int rPin, int gPin, int bPin, Color color) {
  TriLED(rPin, gPin, bPin, color, 1);
}

TriLED::TriLED(int rPin, int gPin, int bPin, Color color, float brightness) {
  m_color = color;
  m_brightness = brightness;

  // Write to pins
  setPins(rPin, gPin, bPin);
  updateLED();
}

void TriLED::setPins(int rPin, int gPin, int bPin) {
  // Set pins
  m_rPin = rPin;
  m_gPin = gPin;
  m_bPin = bPin;

  pinMode(m_rPin, OUTPUT);
  pinMode(m_gPin, OUTPUT);
  pinMode(m_bPin, OUTPUT);
}

void TriLED::setBrightness(float brightness) {
  setColor(m_color, brightness);
}

void TriLED::setColor(Color color) {
  setColor(color, m_brightness);
}

void TriLED::setColor(Color color, float brightness) {
  m_color = color;
  m_brightness = brightness;
  turnOn();
}

void TriLED::updateLED() {
  analogWrite(m_rPin, m_color.r()*m_brightness*m_onStatus);
  analogWrite(m_gPin, m_color.g()*m_brightness*m_onStatus);
  analogWrite(m_bPin, m_color.b()*m_brightness*m_onStatus);
}

void TriLED::turnOn() {
  m_onStatus = HIGH;
  updateLED();
}

void TriLED::turnOff() {
  m_onStatus = LOW;
  updateLED();
}

void TriLED::toggle() {
  m_onStatus = !m_onStatus;
  updateLED();
}

Color::Color() {
  r(0);
  g(0);
  b(0);
}

Color::Color(float rVal, float gVal, float bVal) {
  r(rVal);
  g(gVal);
  b(bVal);
}

void Color::r(float val) {
  m_r = resetBound(val);
}

void Color::g(float val) {
  m_g = resetBound(val);
}

void Color::b(float val) {
  m_b = resetBound(val);
}

float Color::r() {
  return m_r;
}

float Color::g() {
  return m_g;
}

float Color::b() {
  return m_b;
}

// Reset value to 0-255
float resetBound(float val) {
  if (val < 0) {
    return 0;
  }
  else if (val > 255) {
    return 255;
  }
  else {
    return val;
  }
}
