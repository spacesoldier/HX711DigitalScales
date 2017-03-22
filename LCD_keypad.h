#ifndef LCD_KEYPAD_H
#define LCD_KEYPAD_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class LCDKeypad{
private:
  uint8_t keyPin = A0;
public:
  LCDKeypad();
  void initialize();
  
};




#endif
