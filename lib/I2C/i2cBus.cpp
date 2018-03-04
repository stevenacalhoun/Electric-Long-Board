#include <Wire.h>

#include "i2cBus.h"

String currentMessage = "";

I2CDevice* g_device;

I2CBus::I2CBus() {
}

void I2CBus::registerDevice(int address, I2CDevice* device) {
  Wire.begin(address);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  g_device = device;
}

void receiveEvent(int messageCount) {
  while (1 <= Wire.available()) {
    char c = Wire.read();

    if (c == '\0') {
      g_device->receiveEvent(currentMessage);
      currentMessage = "";
    }
    else {
      currentMessage.concat(c);
    }
  }
}

void requestEvent() {
  String message = g_device->requestEvent();
  Wire.write(message.c_str());
  currentMessage = "";
}

