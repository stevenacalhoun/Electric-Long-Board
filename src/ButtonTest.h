#include <project.h>

#include <triLed.h>
#include <button.h>

#pragma once

// Pin defs
#define LED_R_PIN 9
#define LED_G_PIN 10
#define LED_B_PIN 11

#define BUTTON_PIN 7

class ButtonTest: public Project {
  public:
    // Required functions
    ButtonTest();
    void setup();
    void loop();

    // I/O
    TriLED* led;
    Button* button;
};

ButtonTest::ButtonTest() {
  // Init I/O
  led = new TriLED(LED_R_PIN, LED_G_PIN, LED_B_PIN, BLUE, 1);
  button = new Button(BUTTON_PIN);
}

void ButtonTest::setup() {
}

void ButtonTest::loop() {
  // Update button
  button->update();

  // Toggle LED
  if (button->hasToggled()){
    led->toggle();
  }
}
