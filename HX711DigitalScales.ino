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
  // keypad will read user input 10 times a second
  keypad.setReadPeriod(100);
  // lcd screen will be refreshed also 10 times a second
  keypad.setRefreshPeriod(100);
  
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
  checkTime(lastButtonReadTime,keypad.getReadPeriod(),readKeys);
  checkTime(lastScreenRefreshTime,keypad.getRefreshPeriod(),refreshScreen);
}

// here we invoke the callback every given period of time
void checkTime(unsigned long& oldTime, unsigned long period, void callback()){
  if (millis() - oldTime > period ){
    callback();
    oldTime = millis();
  }
}

// wrap the scales measurement call into function
void scalesCallback(){
  scales.checkState(); 
}

// wrap the keys reading call into function
void readKeys(){
  keypad.readUI();
}

// wrap the refresh screen call into function
void refreshScreen(){
  keypad.refreshScreen();
}

