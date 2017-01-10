#include <project.h>

#include <motor.h>
#include <triLed.h>
#include <button.h>
#include <potentiometer.h>

#pragma once

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

    int onOffState = 0;
    float motorSpeed = 0;

    int goNeutralState = 0;
    int reverseToggleState = 0;
    int prevReverseToggleState = 0;

    int revLight = 0;

    TriLED* motorLed;
    Potentiometer* pot;
    Button* goNeutralButton;
    Button* reverseToggleButton;
};

LongBoard::LongBoard() {
  motorLed = new TriLED(LED_R_PIN, LED_G_PIN, LED_B_PIN);
  pot = new Potentiometer(POT_PIN);
  goNeutralButton = new Button(GO_NEUTRAL_PIN);
  reverseToggleButton = new Button(REVERSE_TOGGLE_PIN);
}

void LongBoard::setup() {
  motorLed->setColor(YELLOW, 1);
}

void LongBoard::loop() {
  goNeutralButton->update();
  reverseToggleButton->update();

  if (reverseToggleState != prevReverseToggleState) {
    revLight = 1 - revLight;
  }

  if (goNeutralState == 1) {
    motorLed->setColor(Color(revLight*255,(1-revLight)*255,0), pot->read()/1024.0);
  }
  else {
    motorLed->setColor(YELLOW, 1);
  }
}
