#include "../lib/Project/project.h"

#include "../lib/Controllers/lightController.h"

#pragma once

// Pin defs
#define LED_R_PIN 9
#define LED_G_PIN 10
#define LED_B_PIN 11

#define BUTTON_PIN 7

class LEDStrip : public Project {
  public:
    // Required functions
    LEDStrip();
    void setup();
    void loop();

    LightController lc;
};

LEDStrip::LEDStrip() {
}

void LEDStrip::setup() {
  Color startColor = Color(255, 255, 0);
  lc = LightController(LED_R_PIN, LED_G_PIN, LED_B_PIN, startColor);
  lc.setup();
}

void LEDStrip::loop() {
  lc.update();
}
