#include "lightController.h"

LightController::LightController() {
}

LightController::LightController(int rPin, int gPin, int bPin) {
  Color startColor = Color(255, 255, 255);
  led = TriLED(rPin, gPin, bPin, startColor);

}

LightController::LightController(int rPin, int gPin, int bPin, Color startColor) {
  currentColor = startColor;
  led = TriLED(rPin, gPin, bPin, currentColor, 100);
}

void LightController::setup() {
  i2c = I2C(0x08);
}

void LightController::parseI2CColor(String message) {
  int rVal = message.substring(0, 3).toInt();
  int gVal = message.substring(4, 7).toInt();
  int bVal = message.substring(8, 11).toInt();
  int aVal = message.substring(12, 15).toInt();

  Color messageColor = Color(rVal, gVal, bVal);

  if (messageColor != currentColor) {
    currentColor = messageColor;
    led.setColor(currentColor, aVal);
  }
}

void LightController::update() {
  if (i2c.newMessage() ) {
    String latestMessage = i2c.getLatestMessage();
    parseI2CColor(latestMessage);
  }
}

