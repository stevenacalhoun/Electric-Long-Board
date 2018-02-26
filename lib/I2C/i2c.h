#include <Arduino.h>

class I2C {
  public:
    I2C();
    I2C(int address);
    String getLatestMessage();
    bool newMessage();

};

void receiveEvent(int messageCount);
