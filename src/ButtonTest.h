#include <project.h>

#include <triLed.h>
#include <button.h>

#pragma once

#define LED_R_PIN 9
#define LED_G_PIN 10
#define LED_B_PIN 11

#define BUTTON_PIN 7

class ButtonTest: public Project {
  public:
    ButtonTest();
    void setup();
    void loop();

    TriLED* led;
    Button* button;
};

ButtonTest::ButtonTest() {
  led = new TriLED(LED_R_PIN, LED_G_PIN, LED_B_PIN);
  button = new Button(BUTTON_PIN);
}

void ButtonTest::setup() {
  led->setColor(BLUE, 1);
}

void ButtonTest::loop() {
}
