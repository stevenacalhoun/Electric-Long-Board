#include "i2cLED.h"

I2CLED::I2CLED() {
}

I2CLED::I2CLED(int rPin, int gPin, int bPin, Color color, I2CBus* bus) {
  m_currentColor = color;
  led = TriLED(rPin, gPin, bPin, color, 0.01);
  bus->registerDevice(0x08, this);
}

void I2CLED::receiveEvent(String message) {
  if (message.length() < 10) {
    Serial.println("Set to get " + message);
    m_currentRequest = message;
  }
  else {
    parseI2CColor(message);
  }
}

String I2CLED::requestEvent() {
  if (m_currentRequest == "r") {
    return String(led.getCurrentColor().r());
  }
  else if (m_currentRequest == "g") {
    return String(led.getCurrentColor().g());
  }
  else if (m_currentRequest == "b") {
    return String(led.getCurrentColor().b());
  }
  else if (m_currentRequest == "rgb") {
    String resp = String((int)led.getCurrentColor().r()) + "-" +
    String((int)led.getCurrentColor().g()) + "-" +
    String((int)led.getCurrentColor().b());
    return resp;
  }
  else {
    return "invalid";
  }
}

void I2CLED::parseI2CColor(String message) {
  m_currentColor = Color(
    message.substring(0, 3).toInt(),
    message.substring(4, 7).toInt(),
    message.substring(8, 11).toInt()
  );

  led.setTargetColor(m_currentColor);
}

void I2CLED::update() {
  if (led.getCurrentColor() != led.getTargetColor()) {
    if (led.getCurrentColor().closeTo(led.getTargetColor())) {
      led.setCurrentColor(led.getTargetColor());
    }

    else {
      led.moveToTarget();
    }
  }

}
