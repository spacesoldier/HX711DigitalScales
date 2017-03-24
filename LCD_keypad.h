#ifndef LCD_KEYPAD_H
#define LCD_KEYPAD_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "callable.h"

class LCDKeypad: public Callable{
private:
  uint8_t keyPin = A0;
public:
  LCDKeypad();
  void initialize();
  void callback();
  void callback(uint8_t);
};




#endif
