#include "colorRGB.h"
#include "colorHSV.h"

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

ColorRGB::ColorRGB() {
  r(0);
  g(0);
  b(0);
}

ColorRGB::ColorRGB(float rVal, float gVal, float bVal) {
  rgb(rVal, gVal, bVal);
}

void ColorRGB::rgb(float rVal, float gVal, float bVal) {
  r(rVal);
  g(gVal);
  b(bVal);
}

void ColorRGB::r(float val) {
  m_c1 = resetBound(val);
}

void ColorRGB::g(float val) {
  m_c2 = resetBound(val);
}

void ColorRGB::b(float val) {
  m_c3 = resetBound(val);
}

float ColorRGB::r() {
  return m_c1;
}

float ColorRGB::g() {
  return m_c2;
}

float ColorRGB::b() {
  return m_c3;
}

ColorHSV ColorRGB::toHSV() {
  float rVal = r()/255.0;
  float gVal = g()/255.0;
  float bVal = b()/255.0;
  float maxVal = max(max(rVal, gVal), bVal);
  float minVal = min(min(rVal, gVal), bVal);

  float h = maxVal;
  float s = maxVal;
  float v = maxVal;
  float d = maxVal - minVal;

  s = maxVal == 0 ? 0 : d / maxVal;
  if (maxVal == minVal) {
    h = 0;
  }
  else {
    if (maxVal == rVal) {
      h = (gVal - bVal) / d + (gVal < bVal ? 6 : 0);
    }
    else if (maxVal == gVal) {
      h = (bVal - rVal) / d + 2;
    }
    else if (maxVal == bVal) {
      h = (rVal - gVal) / d + 4;
    }
    h /= 6;
  }

  return ColorHSV(h*360, s*100, v*100);
}

