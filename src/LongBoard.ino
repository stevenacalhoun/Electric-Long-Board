#include "motor.h"
#include "triLed.h"
#include "inputs.h"

#include "colorDefs.h"
#include "pinDefs.h"

int onOffState = 0;
float motorSpeed = 0;

int goNeutralState = 0;
int reverseToggleState = 0;
int prevReverseToggleState = 0;

int revLight = 0;

Motor* motor;
TriLED* motorLed;
Potentiometer* pot;
Button* goNeutralButton;
Button* reverseToggleButton;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  motor = new Motor();
  motorLed = new TriLED(LED_R_PIN, LED_G_PIN, LED_B_PIN);
  pot = new Potentiometer(POT_PIN);
  goNeutralButton = new Button(GO_NEUTRAL_PIN);
  reverseToggleButton = new Button(REVERSE_TOGGLE_PIN);
}

void loop() {
  goNeutralState = goNeutralButton->read();
  reverseToggleState = reverseToggleButton->read();

  delay(1);

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
