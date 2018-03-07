#include "i2cLED.h"

I2CLED::I2CLED() {
}

I2CLED::I2CLED(int rPin, int gPin, int bPin, ColorHSV color, I2CBus* bus) {
  m_currentColor = color;
  m_led = TriLED(rPin, gPin, bPin, color.toRGB(), 0.002);
  bus->registerDevice(0x08, this);
}

void I2CLED::receiveEvent(String message) {
  if (message.startsWith("h")) {
    m_currentColor.h(message.substring(1).toFloat());
    updateLED(m_currentColor.toRGB());
  }
  else if (message.startsWith("s")) {
    m_currentColor.s(message.substring(1).toFloat());
    updateLED(m_currentColor.toRGB());
  }
  else if (message.startsWith("v")) {
    m_currentColor.v(message.substring(1).toFloat());
    updateLED(m_currentColor.toRGB());
  }
  else if (message.startsWith("o")) {
    int onVal = message.substring(1).toInt();
    //m_led.onState(onVal);
  }
  else if (message.startsWith("q")) {
    m_currentRequest = message.substring(1, 2);
  }

  if (message.length() == 1) {
    Serial.println("Set to get " + message);
    message = message;
  }
  else if (message == "on") {
    m_led.turnOn();
  }
  else if (message == "off") {
    m_led.turnOff();
  }
}

String I2CLED::requestEvent() {
  String resp = "Invalid";

  if (m_currentRequest == "h") {
    resp = String((int)m_currentColor.h());
    return resp;
  }
  else if (m_currentRequest == "s") {
    resp = String((int)m_currentColor.s());
    return resp;
  }
  else if (m_currentRequest == "v" ) {
    resp = String((int)m_currentColor.v());
    return resp;
  }
  else if (m_currentRequest.startsWith("o")) {
    //resp = m_led.onState ? "1" : "0";
  }
  return resp;
}

void I2CLED::updateLED(ColorRGB color) {
  m_led.setTargetColor(color);
}

void I2CLED::update() {
  if (m_led.getCurrentColor() != m_led.getTargetColor()) {
    if (m_led.getCurrentColor().closeTo(m_led.getTargetColor())) {
      m_led.setCurrentColor(m_led.getTargetColor());
    }

    else {
      m_led.moveToTarget();
    }
  }

}
