#include "Arduino.h"

#include "colorCube.h"

ColorCube::ColorCube() {
}

ColorCube::ColorCube(Color colorPositions[], int numPositions, float speed) {
  m_colorPositions = colorPositions;
  m_speed = speed;
  m_numPositions = numPositions;
  m_vi1 = 0;
  m_vi2 = 1;
  m_currentColor = m_colorPositions[m_vi1];

}

Color ColorCube::step() {
  Color color1 = m_colorPositions[m_vi1];
  Color color2 = m_colorPositions[m_vi2];

  if (m_currentColor == color2) {
    m_vi1++;
    m_vi2++;
  }

  if (m_vi1 == m_numPositions) m_vi1 = 0;
  if (m_vi2 == m_numPositions) m_vi2 = 0;

  traverse(color1, color2);

  return m_currentColor;
}

void ColorCube::traverse(Color startColor, Color endColor) {
  int dR = (endColor.r() - startColor.r())*m_speed;
  int dG = (endColor.g() - startColor.g())*m_speed;
  int dB = (endColor.b() - startColor.b())*m_speed;;

  m_currentColor.rgb(m_currentColor.r() + dR,
                     m_currentColor.g() + dG,
                     m_currentColor.b() + dB);
}

Color ColorCube::currentColor() {
  return m_currentColor;
}
