#include "triLED.h"

float SPEED = 0.01;

TriLED::TriLED() {
}

TriLED::TriLED(int rPin, int gPin, int bPin) {
  TriLED(rPin, gPin, bPin, Color(), 1);
}

TriLED::TriLED(int rPin, int gPin, int bPin, Color color) {
  m_color = color;
  m_targetColor = m_color;
  m_previousColor = m_color;
  TriLED(rPin, gPin, bPin, color, 1);
}

TriLED::TriLED(int rPin, int gPin, int bPin, Color color, float brightness) {
  m_color = color;
  m_targetColor = m_color;
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
  analogWrite(m_rPin, m_color.r()*(m_brightness*m_onStatus/100.0));
  analogWrite(m_gPin, m_color.g()*(m_brightness*m_onStatus/100.0));
  analogWrite(m_bPin, m_color.b()*(m_brightness*m_onStatus/100.0));
}

void TriLED::setColorTarget(Color targetColor) {
  m_targetColor = targetColor;
  m_previousColor = m_color;
}

void TriLED::moveToTarget() {
  int dR = (m_targetColor.r() - m_previousColor.r())*SPEED;
  int dG = (m_targetColor.g() - m_previousColor.g())*SPEED;
  int dB = (m_targetColor.b() - m_previousColor.b())*SPEED;;

  m_color.rgb(
    m_color.r() + dR,
    m_color.g() + dG,
    m_color.b() + dB
  );
  updateLED();
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

