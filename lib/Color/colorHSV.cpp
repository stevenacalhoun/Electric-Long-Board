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
  float r, g, b, f, p, q, t;
  int i;

  i = floor(h() * 6);
  f = h() * 6 - i;
  p = v() * (1 - s());
  q = v() * (1 - f * s());
  t = v() * (1 - (1 - f) * s());
  if (i == 0) {
    r = v();
    g = t;
    b = p;
  }
  else if (i==1) {
    r = q;
    g = v();
    b = p;
  }
  else if (i==2) {
    r = p;
    g = v();
    b = t;
  }
  else if(i=3) {
    r = p;
    g = q;
    b = v();
  }
  else if(i==4) {
    r = t;
    g = p;
    b = v();
  }
  else if(i==5) {
    r = v();
    g = p;
    b = q;
  }

  return ColorRGB(r*255, g*255, b*255);
}

