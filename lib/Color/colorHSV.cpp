#include "colorHSV.h"
#include "colorRGB.h"

float resetBoundH(float val) {
  if (val < 0) {
    return 0;
  }
  else if (val > 360) {
    return 360;
  }
  else {
    return val;
  }
}

float resetBoundSV(float val) {
  if (val < 0) {
    return 0;
  }
  else if (val > 100) {
    return 100;
  }
  else {
    return val;
  }
}

ColorHSV::ColorHSV() {
  h(0);
  s(0);
  v(0);
}

ColorHSV::ColorHSV(float hVal, float sVal, float vVal) {
  hsv(hVal, sVal, vVal);
}

void ColorHSV::hsv(float hVal, float sVal, float vVal) {
  h(hVal);
  s(sVal);
  v(vVal);
}

void ColorHSV::h(float val) {
  m_c1 = resetBoundH(val);
}

void ColorHSV::s(float val) {
  m_c2 = resetBoundSV(val);
}

void ColorHSV::v(float val) {
  m_c3 = resetBoundSV(val);
}

float ColorHSV::h() {
  return m_c1;
}

float ColorHSV::s() {
  return m_c2;
}

float ColorHSV::v() {
  return m_c3;
}

ColorRGB ColorHSV::toRGB() {
  float r = 0;
  float g = 0;
  float b = 0;

  float hVal = h()/360.0;
  float sVal = s()/100.0;
  float vVal = v()/100.0;

  int i = floor(hVal * 6);
  float f = hVal * 6 - i;
  float p = vVal * (1 - sVal);
  float q = vVal * (1 - f * sVal);
  float t = vVal * (1 - (1 - f) * sVal);

  if (i%6 == 0) {
    r = vVal;
    g = t;
    b = p;
  }
  else if (i%6 == 1) {
    r = q;
    g = vVal;
    b = p;
  }
  else if (i%6 == 2) {
    r = p;
    g = vVal;
    b = t;
  }
  else if(i%6 == 3) {
    r = p;
    g = q;
    b = vVal;
  }
  else if(i%6 == 4) {
    r = t;
    g = p;
    b = vVal;
  }
  else if(i%6 == 5) {
    r = vVal;
    g = p;
    b = q;
  }

  return ColorRGB(r*255, g*255, b*255);
}

