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
  float maxVal = max(max((r()/255), (g()/255)), (b()/255));
  float minVal = min(min((r()/255), (g()/255)), (b()/255));

  float h = maxVal;
  float s = maxVal;
  float v = maxVal;
  float d = maxVal - minVal;

  s = maxVal == 0 ? 0 : d / maxVal;
  if (maxVal == minVal) {
    h = 0;
  }
  else {
    if (maxVal == r()/255) {
      h = ((g()/255) - (b()/255)) / d + ((g()/255)< (b()/255)? 6 : 0);
    }
    else if (maxVal == g()/255) {
      h = ((b()/255)- (r()/255)) / d + 2;
    }
    else if (maxVal == b()/255) {
      h = ((r()/255)- (g()/255)) / d + 4;
    }
    h /= 6;
  }

  return ColorHSV(h*360, s*100, v*100);
}

