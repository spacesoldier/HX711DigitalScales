#include "digital_scale.h"

DigitalScale::DigitalScale(){
  state = 0;
}


void DigitalScale::initialize(){
  scale.begin(HX711_DOUT, HX711_PD_SCK);
  scale.set_scale(2280.f);     // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();                // reset the scale to 0
}


void DigitalScale::tare(){
  
}

void DigitalScale::setWeigtLimit(){
  
}


bool DigitalScale::weightAchieved(){
  
}




