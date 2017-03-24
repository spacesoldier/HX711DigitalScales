#include "digital_scale.h"

DigitalScale::DigitalScale(){
  state = 0;
  currWeight = 0.0;
  needWeight = 0.0;
  delta = 0.0;
}


void DigitalScale::initialize(){
  scale.begin(HX711_DOUT, HX711_PD_SCK);
  scale.set_scale(2280.f);     // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();                // reset the scale to 0
}


void DigitalScale::tare(){
  currWeight = 0.0;
}

void DigitalScale::setWeigtLimit(double lim){
  needWeight = lim;
}


bool DigitalScale::weightAchieved(){
  if (abs(needWeight - currWeight) < delta){
    return true;
  } else {
    return false;
  }
}

void DigitalScale::setHandler(Callable* handle){
  handler = handle;
}

void DigitalScale::readWeight(){
  scale.power_up();
  scale.get_units(5);
  scale.power_down();
}

void DigitalScale::checkState(){
  readWeight();
  if (weightAchieved()){
    state++;
    notifyHandler();
  }
}

void DigitalScale::notifyHandler(){
  if (handler != NULL){
      handler -> callback();
      handler -> callback(state);
  }
}

