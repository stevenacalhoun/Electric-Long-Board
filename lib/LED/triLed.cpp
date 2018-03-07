#include "triLED.h"

TriLED::TriLED() {
}

TriLED::TriLED(int rPin, int gPin, int bPin, ColorRGB color, float transitionSpeed) {
  m_currentColor = color;
  m_targetColor = m_currentColor;
  m_transitionSpeed = transitionSpeed;

  // Set pins
  m_rPin = rPin;
  m_gPin = gPin;
  m_bPin = bPin;

  pinMode(m_rPin, OUTPUT);
  pinMode(m_gPin, OUTPUT);
  pinMode(m_bPin, OUTPUT);

  // Show initial Color
  writeLEDValues();
}

ColorRGB TriLED::getCurrentColor() {
  return m_currentColor;
}

void TriLED::setCurrentColor(ColorRGB color) {
  m_currentColor = color;
  turnOn();
}

ColorRGB TriLED::getTargetColor() {
  return m_targetColor;
}

void TriLED::setTargetColor(ColorRGB color) {
  m_previousColor = m_currentColor;
  m_targetColor = color;

  m_dR = (m_targetColor.r() - m_previousColor.r())*m_transitionSpeed;
  m_dG = (m_targetColor.g() - m_previousColor.g())*m_transitionSpeed;
  m_dB = (m_targetColor.b() - m_previousColor.b())*m_transitionSpeed;
}

ColorRGB TriLED::getPreviousColor() {
  return m_previousColor;
}

void TriLED::setPreviousColor(ColorRGB color) {
  m_previousColor = color;
}

float TriLED::getTransitionSpeed() {
  return m_transitionSpeed;
}

void TriLED::setTransitionSpeed(float transitionSpeed) {
  m_transitionSpeed = transitionSpeed;
}

void TriLED::writeLEDValues() {
  analogWrite(m_rPin, m_currentColor.r());
  analogWrite(m_gPin, m_currentColor.g());
  analogWrite(m_bPin, m_currentColor.b());
}

void TriLED::moveToTarget() {
  m_currentColor.rgb(
    m_currentColor.r() + m_dR,
    m_currentColor.g() + m_dG,
    m_currentColor.b() + m_dB
  );

  writeLEDValues();
}

bool TriLED::getOnState() {
  return m_onStatus;
}

void TriLED::turnOn() {
  m_onStatus = HIGH;
  writeLEDValues();
}

void TriLED::turnOff() {
  m_onStatus = LOW;
  writeLEDValues();
}

void TriLED::toggle() {
  m_onStatus = !m_onStatus;
  writeLEDValues();
}

