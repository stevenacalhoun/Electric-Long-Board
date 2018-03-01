#include "lightController.h"

LightController::LightController() {
}

LightController::LightController(int rPin, int gPin, int bPin) {
  Color startColor = Color(255, 255, 255);
  led = TriLED(rPin, gPin, bPin, startColor);

}

LightController::LightController(int rPin, int gPin, int bPin, Color color) {
  currentColor = color;
  led = TriLED(rPin, gPin, bPin, currentColor, 100);
}

void LightController::setup() {
  i2c = I2C(0x08);
}

void LightController::parseI2CColor(String message) {
  Serial.println(message);

  currentColor = Color(
    message.substring(0, 3).toInt(),
    message.substring(4, 7).toInt(),
    message.substring(8, 11).toInt()
  );

  led.setColor(currentColor, message.substring(12, 15).toInt());
}

void LightController::update() {
  if (i2c.newMessage() ) {
    parseI2CColor(i2c.getLatestMessage());
  }
}

