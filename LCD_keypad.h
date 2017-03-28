#ifndef LCD_KEYPAD_H
#define LCD_KEYPAD_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "callable.h"
#include "dataprovider.h"

class LCDKeypad: public Callable{
private:
  uint8_t keyPin = A0;
  int screenPeriod;
  int keysReadPeriod;
  DataProvider* scales;
public:
  LCDKeypad();
  void initialize();
  void callback();
  void callback(uint8_t);
  void setSource(DataProvider*);
};




#endif
