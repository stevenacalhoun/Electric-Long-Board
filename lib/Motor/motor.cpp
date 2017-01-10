#include "motor.h"

Motor::Motor() {
  m_speed = 0.0;
  m_direction = forward;
}

void Motor::speed(float percentage) {
  m_speed = percentage;
}

void Motor::direction(Direction dir) {
  m_direction = dir;
}

float Motor::speed() {
  return m_speed;
}

float Motor::direction() {
  return m_direction;
}
