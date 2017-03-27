#include "LCD_keypad.h"

LCDKeypad::LCDKeypad(){
  scales = NULL;
  
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

