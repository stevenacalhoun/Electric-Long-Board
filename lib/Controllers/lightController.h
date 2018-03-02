#include <Arduino.h>
#include <Wire.h>

#include "../LED/triLED.h"
#include "../Color/color.h"
#include "../I2C/i2c.h"

class LightController {
  public:
    LightController();
    LightController(int rPin, int gPin, int bPin);
    LightController(int rPin, int gPin, int bPin, Color startColor);

    void setup();
    void update();

    static void receiveEvent(int numMessages);
    static String currentMessage;
    static bool changed;

    void parseI2CColor(String message);

  private:
    TriLED led;
    Color currentColor;
    Color colorTarget;

    I2C i2c;
};
