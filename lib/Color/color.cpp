#include "color.h"
#include "Arduino.h"

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
Color::Color() {
  r(0);
  g(0);
  b(0);
}

Color::Color(float rVal, float gVal, float bVal) {
  rgb(rVal, gVal, bVal);
}

bool Color::operator==(Color other) {
  return ((m_r == other.r()) && (m_g == other.g()) && (m_b == other.b()));
}

void Color::rgb(float rVal, float gVal, float bVal) {
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

void Color::print() {
  Serial.print("r: ");
  Serial.println(m_r);

  Serial.print("g: ");
  Serial.println(m_g);

  Serial.print("b: ");
  Serial.println(m_b);
}
