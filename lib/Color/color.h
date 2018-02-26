#pragma once

class Color {
  private:
    float m_r;
    float m_g;
    float m_b;

  public:
    Color();
    Color(float r, float g, float b);

    bool operator==(Color other);
    bool operator!=(Color other);

    // Getter/setter for each channel
    float r();
    float g();
    float b();
    void r(float val);
    void g(float val);
    void b(float val);
    void rgb(float rVal, float gVal, float bVal);

    void print();
};

