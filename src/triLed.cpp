#include "triLed.h"

TriLED::TriLED(int rPin, int gPin, int bPin) {
  m_color = Color();
  m_brightness = 0;

  m_rPin = rPin;
  m_gPin = gPin;
  m_bPin = bPin;

  pinMode(m_rPin, OUTPUT);
  pinMode(m_gPin, OUTPUT);
  pinMode(m_bPin, OUTPUT);

  writeColor();
}

TriLED::TriLED(int rPin, int gPin, int bPin, Color color) {
  m_color = color;
  writeColor();
}

void TriLED::setBrightness(float brightness) {
  m_brightness = brightness;
  writeColor();
}

void TriLED::setColor(Color color) {
  m_color = color;
  writeColor();
}

void TriLED::setColor(Color color, float brightness) {
  m_color = color;
  m_brightness = brightness;
  writeColor();
}

void TriLED::writeColor() {
  analogWrite(m_rPin, m_color.r()*m_brightness);
  analogWrite(m_gPin, m_color.g()*m_brightness);
  analogWrite(m_bPin, m_color.b()*m_brightness);
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
