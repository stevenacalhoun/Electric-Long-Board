#include "color.h"
#include "Arduino.h"

#define TOLERANCE 2

Color::Color() {
  m_c1 = 0;
  m_c2 = 0;
  m_c3 = 0;
}

Color::Color(float c1, float c2, float c3) {
  m_c1 = c1;
  m_c2 = c2;
  m_c3 = c3;
}

bool Color::operator==(Color other) {
  return ((m_c1 == other.c1()) && (m_c2 == other.c2()) && (m_c3 == other.c3()));
}

bool Color::operator!=(Color other) {
  return ((m_c1 != other.c1()) || (m_c2 != other.c2()) || (m_c1 != other.c3()));
}

bool Color::closeTo(Color other) {
  bool c1Close = false;
  bool c2Close = false;
  bool c3Close = false;

  c1Close = (((m_c1 - TOLERANCE) < other.c1()) && (other.c1() < (m_c1 + TOLERANCE)));
  c2Close = (((m_c2 - TOLERANCE) < other.c2()) && (other.c2() < (m_c2 + TOLERANCE)));
  c3Close = (((m_c3 - TOLERANCE) < other.c3()) && (other.c3() < (m_c3 + TOLERANCE)));

  return c1Close && c2Close && c3Close;
}

float Color::c1() {
  return m_c1;
}

float Color::c2() {
  return m_c2;
}

float Color::c3() {
  return m_c3;
}

void Color::print() {
  Serial.print("c1: ");
  Serial.println(m_c1);

  Serial.print("c2: ");
  Serial.println(m_c2);

  Serial.print("c3: ");
  Serial.println(m_c3);
}
