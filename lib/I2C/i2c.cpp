#include <Wire.h>

#include "i2c.h"

#define MAX_NUM_MESSAGES 20

int currentMessageIndex = 0;
String currentMessage = "000-000-000-000";
int i=0;
bool changed = false;

String i2cMessages[MAX_NUM_MESSAGES];

I2C::I2C() {
}

I2C::I2C(int address) {
  Wire.begin(address);
  Wire.onReceive(receiveEvent);
}

bool I2C:: newMessage() {
  return changed;
}

String I2C::getLatestMessage() {
  int lookupIndex = currentMessageIndex - 1;
  if (lookupIndex < 0) currentMessageIndex = MAX_NUM_MESSAGES;

  changed = false;
  return i2cMessages[currentMessageIndex-1];
}


void receiveEvent(int messageCount) {
  while (1 <= Wire.available()) {
    char c = Wire.read();
    if (c == '\0') {
      i2cMessages[currentMessageIndex++] = currentMessage;
      i = 0;
      changed = true;
      if (currentMessageIndex == MAX_NUM_MESSAGES) {
        currentMessageIndex = 0;
      }
    }
    else {
      currentMessage.setCharAt(i++, c);
    }
  }
}
