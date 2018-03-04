#include "../lib/Project/project.h"

#include "../lib/Controllers/i2cLED.h"
#include "../lib/I2C/i2cBus.h"

#pragma once

#define LED_R_PIN 9
#define LED_G_PIN 10
#define LED_B_PIN 11

class I2CTest : public Project {
  public:
    // Required functions
    I2CTest();
    void setup();
    void loop();

    I2CBus* bus;
    I2CLED* led;

    bool first;
};

I2CTest::I2CTest() {
}

void I2CTest::setup() {
  Serial.println("Startup");
  first = true;
  bus = new I2CBus();
  led = new I2CLED(LED_R_PIN, LED_G_PIN, LED_B_PIN, Color(255, 255, 255), bus);
}

void I2CTest::loop() {
  led->update();
  if (first) {
    led->parseI2CColor("255-000-000");
    first = false;
  }
}
