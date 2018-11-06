#include <project.h>

#include <bluetooth.h>

#pragma once

// Pin defs
#define MOD_LINE 12
#define CTS_LINE 6
#define TXO_LINE 5
#define RXI_LINE 3
#define RTS_LINE 8

class BLTest: public Project {
  public:
    // Required functions
    BLTest();
    void setup();
    void loop();

    BlueTooth BL = BlueTooth(MOD_LINE, CTS_LINE, TXO_LINE, RXI_LINE, RTS_LINE);
};

BLTest::BLTest() {
  Serial.println("Construct");
}

void BLTest::setup() {
  Serial.println("Starting");
  BL.run();
}

void BLTest::loop() {
}
