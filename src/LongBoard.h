#include <project.h>

#include <motor.h>
#include <triLed.h>
#include <button.h>
#include <potentiometer.h>

#pragma once

// Pin defs
#define POT_PIN A0

#define LED_R_PIN 9
#define LED_G_PIN 10
#define LED_B_PIN 11

#define GO_NEUTRAL_PIN 7
#define REVERSE_TOGGLE_PIN 8

class LongBoard: public Project {
  public:
    LongBoard();
    void setup();
    void loop();

    // I/O
    TriLED* motorLed;
    Potentiometer* pot;
    Button* goButton;
    Button* reverseToggleButton;

    // Reverse status
    int reverse = 0;
};

LongBoard::LongBoard() {
  // Init I/O
  motorLed = new TriLED(LED_R_PIN, LED_G_PIN, LED_B_PIN, YELLOW, 1);
  pot = new Potentiometer(POT_PIN);
  goButton = new Button(GO_NEUTRAL_PIN);
  reverseToggleButton = new Button(REVERSE_TOGGLE_PIN);
}

void LongBoard::setup() {
}

void LongBoard::loop() {
  // Update buttons
  goButton->update();
  reverseToggleButton->update();

  // Toggle reverse
  if (reverseToggleButton->hasToggled()) {
    reverse = !reverse;
  }

  // Change based on go or not
  if (goButton->read() == 1) {
    motorLed->setColor(Color(reverse*255,(!reverse)*255,0), pot->read()/1024.0);
  }
  else {
    motorLed->setColor(YELLOW, 1);
  }
}
