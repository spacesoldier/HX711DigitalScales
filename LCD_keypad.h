#ifndef LCD_KEYPAD_H
#define LCD_KEYPAD_H

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "callable.h"
#include "dataprovider.h"

class LCDKeypad: public Callable{
private:
  LiquidCrystal lcd = LiquidCrystal(8,9,4,5,6,7);
  uint8_t keyPin = A0;
  int screenPeriod;
  int keysReadPeriod;
  DataProvider* scales;
  uint8_t brightnessPin = 10;
  enum ButtonCodes{
    RIGHT,
    UP,
    DOWN,
    LEFT,
    SELECT,
    NONE
  };
  uint8_t getButtonCode();
public:
  LCDKeypad();
  void initialize();
  void setBrightness(int);
  void callback();
  void callback(uint8_t);
  void setSource(DataProvider*);
  void setReadPeriod(int);
  void setRefreshPeriod(int);
  int getReadPeriod();
  int getRefreshPeriod();
  void refreshScreen();
  void readUI();
};




#endif
