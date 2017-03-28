#include "LCD_keypad.h"

LCDKeypad::LCDKeypad(){
  scales = NULL;
  screenPeriod = 0;
  keysReadPeriod = 0;
}

void LCDKeypad::setSource(DataProvider * source){
  scales = source;
}

void LCDKeypad::initialize(){
  
}

void LCDKeypad::callback(){
  
}

void LCDKeypad::callback(uint8_t state){
  
}

