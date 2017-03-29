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
  pinMode(keyPin,INPUT);
  lcd.begin(16,2);
  lcd.clear();
}

void LCDKeypad::setBrightness(int val){
  analogWrite(brightnessPin,val);
}

void LCDKeypad::callback(){
  
}

void LCDKeypad::callback(uint8_t state){
  
}

void LCDKeypad::setReadPeriod(int period){
  keysReadPeriod = period;
}

void LCDKeypad::setRefreshPeriod(int period){
  screenPeriod = period;
}


int LCDKeypad::getReadPeriod(){
  return keysReadPeriod;
}

int LCDKeypad::getRefreshPeriod(){
  return screenPeriod;
}

uint8_t LCDKeypad::getButtonCode(){
  int x = analogRead(keyPin);
  if (x < 60) { 
    return RIGHT;
  } 
  else if (x < 200) { 
    return UP;
  } 
  else if (x < 400){ 
    return DOWN;
  } 
  else if (x < 600){ 
    return LEFT;
  } 
  else if (x < 800){ 
    return SELECT; 
  }
  return NONE;
}

void LCDKeypad::readUI(){
   uint8_t code = getButtonCode();
   switch (code) {
    case SELECT:
      break;
    case UP:
      break;
    case DOWN:
      break;      
    case LEFT:
      break;
    case RIGHT:
      break;
   }
}

void LCDKeypad::refreshScreen(){
  if (scales != NULL){
    lcd.setCursor(0,0);
    lcd.print("Weight: ");
    lcd.print(scales->getData(),1);
  }
}

