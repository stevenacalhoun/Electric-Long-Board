#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_UART.h"
#include "BluefruitConfig.h"

#include "bluetooth.h"

BlueTooth::BlueTooth() {
}

BlueTooth::BlueTooth(
  int modLine,
  int ctsLine,
  int txoLine,
  int rxiLine,
  int rtsLine
) {
}

void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

void BlueTooth::run() {
  SoftwareSerial bluefruitSS = SoftwareSerial(BLUEFRUIT_SWUART_TXD_PIN, BLUEFRUIT_SWUART_RXD_PIN);

  Adafruit_BluefruitLE_UART ble(bluefruitSS, BLUEFRUIT_UART_MODE_PIN,
                        BLUEFRUIT_UART_CTS_PIN, BLUEFRUIT_UART_RTS_PIN);

  Serial.println("Beginning");
  if (!ble.begin(VERBOSE_MODE)) {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }

  Serial.println("Factory resetting");
  if (!ble.factoryReset()) {
    error(F("Couldn't factory reset"));
  }

  Serial.println("Disable echo");
  ble.echo(false);

  Serial.println("Requesting Bluefruit info:");
  ble.info();

  Serial.println(F("Setting device name to 'Bluefruit HRM': "));
  if (! ble.sendCommandCheckOK(F("AT+GAPDEVNAME=Bluefruit HRM")) ) {
    error(F("Could not set device name?"));
  }

}
