#pragma once

enum Direction {forward, reverse};

class Motor {
  private:
    float m_speed;
    Direction m_direction;

  public:
    Motor();

    void speed(float percentage);
    void direction(Direction dir);

    float speed();
    float direction();
};
