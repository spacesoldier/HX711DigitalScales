#include "digital_scale.h"
#include "LCD_keypad.h"

DigitalScale scales;
LCDKeypad keypad;

void setup() {
  scales.setHandler(&keypad);
  keypad.setSource(&scales);
  
  // Scale init:
  scales.initialize();
  // keypad init
  keypad.initialize();

}

void loop() {
  // put your main code here, to run repeatedly:

}

// here we invoke the callback every given period of time
void checkTime(unsigned long& oldTime, unsigned long period, void callback()){
  if (millis() - oldTime > period ){
    callback();
    oldTime = millis();
  }
}


