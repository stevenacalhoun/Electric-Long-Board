#pragma once

class Color {
  protected:
    float m_c1;
    float m_c2;
    float m_c3;

  public:
    Color();
    Color(float c1, float c2, float c3);

    bool operator==(Color other);
    bool operator!=(Color other);
    bool closeTo(Color other);

    void print();

    float c1();
    float c2();
    float c3();
};

