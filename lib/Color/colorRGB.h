#include "color.h"

#include <Arduino.h>

#pragma once

class ColorHSV;
class ColorRGB : public Color {
  public:
    ColorRGB();
    ColorRGB(float r, float g, float b);

    // Getter/setter for each channel
    float r();
    float g();
    float b();
    void r(float val);
    void g(float val);
    void b(float val);
    void rgb(float rVal, float gVal, float bVal);

    ColorHSV toHSV();
};

