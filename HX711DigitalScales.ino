#include "digital_scale.h"
#include "LCD_keypad.h"
#include "relay_module.h"

DigitalScale scales;
unsigned long lastMeasureTime = 0;

LCDKeypad keypad;
unsigned long lastButtonReadTime = 0;
unsigned long lastScreenRefreshTime = 0;

RelayModule relays;

void setup() {
  //setup scales
  // scales will notify the keypad shield when the weight is reached
  scales.setHandler(&keypad);
  // scales will measure weight 5 times a second
  scales.setPeriod(200);

  // setup keypad
  // keypad will get the data from scales
  keypad.setSource(&scales);
  
  // Scale init:
  scales.initialize();
  // keypad init
  keypad.initialize();

  // init the relay block
  relays.initialize();

}

void loop() {
  
  // check the state of the scales: measure and compare weight
  checkTime(lastMeasureTime,scales.getPeriod(),scalesCallback);
}

// here we invoke the callback every given period of time
void checkTime(unsigned long& oldTime, unsigned long period, void callback()){
  if (millis() - oldTime > period ){
    callback();
    oldTime = millis();
  }
}

void scalesCallback(){
  scales.checkState(); 
}

