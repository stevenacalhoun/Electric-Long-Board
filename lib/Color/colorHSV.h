#include "color.h"

#pragma once

class ColorRGB;
class ColorHSV : public Color {
  public:
    ColorHSV();
    ColorHSV(float h, float s, float v);

    // Getter/setter for each channel
    float h();
    float s();
    float v();
    void h(float val);
    void s(float val);
    void v(float val);
    void hsv(float hVal, float sVal, float vVal);

    ColorRGB toRGB();
};

