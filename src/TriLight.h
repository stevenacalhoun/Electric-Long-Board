#include "../lib/Project/project.h"

#include "../lib/LED/triLed.h"
#include "../lib/Color/colorCube.h"
#include "../lib/Color/color.h"

#pragma once

// Pin defs
#define LED_R_PIN 9
#define LED_G_PIN 10
#define LED_B_PIN 11

class TriLight: public Project {
  public:
    // Required functions
    TriLight();
    void setup();
    void loop();

    // I/O
    TriLED* led;

    ColorCube cube;
    int i;

    Color m_colors[6];
};

TriLight::TriLight() {
  m_colors[0] = Color(255,0,0);
  m_colors[1] = Color(0,255,0);
  m_colors[2] = Color(0,0,255);
  m_colors[3] = Color(0,255,255);
  m_colors[4] = Color(255,0,255);
  m_colors[5] = Color(255,255,0);

  // Init I/O
  led = new TriLED(LED_R_PIN, LED_G_PIN, LED_B_PIN, BLUE, 1);

}

void TriLight::setup() {
  float speed = 0.1;
  int numPositions = sizeof(m_colors)/sizeof(m_colors[0]);
  cube = ColorCube(m_colors, numPositions, speed);

  led->setColor(cube.currentColor());
}

void TriLight::loop() {
  i++;

  if (i>100) {
    Color newColor = cube.step();
    led->setColor(newColor);
    i=0;
  }
}
