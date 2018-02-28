#include "color.h"

#pragma once

class ColorCube {
  public:
    ColorCube();
    ColorCube(Color positions[], int numPositions, float speed);

    Color step();
    Color currentColor();

  private:
    Color* m_colorPositions;
    Color m_currentColor;

    int m_vi1;
    int m_vi2;
    int m_numPositions;

    float m_speed;

    void traverse(Color startColor, Color endColor);

};
