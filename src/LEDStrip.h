#include "../lib/Project/project.h"

#include "../lib/LED/i2cLED.h"
#include "../lib/I2C/i2cBus.h"

#pragma once

// Pin defs
#define LED_R_PIN 10
#define LED_G_PIN 9
#define LED_B_PIN 11

class LEDStrip : public Project {
  public:
    // Required functions
    LEDStrip();
    void setup();
    void loop();

    I2CBus* bus;
    I2CLED* led;
};

LEDStrip::LEDStrip() {
}

void LEDStrip::setup() {
  bus = new I2CBus();
  led = new I2CLED(LED_R_PIN, LED_G_PIN, LED_B_PIN, ColorHSV(0, 0, 0), bus);
}

void LEDStrip::loop() {
  led->update();
}
