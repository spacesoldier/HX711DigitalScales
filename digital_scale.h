#ifndef DIGITAL_SCALE_H
#define DIGITAL_SCALE_H

#include <Arduino.h>
#include "HX711.h"


class DigitalScale{

private:
  uint8_t HX711_DOUT = A2;
  uint8_t HX711_PD_SCK = A1;
  
  HX711 scale;    // parameter "gain" is ommited; the default value 128 is used by the library

  uint8_t state;
public:
  DigitalScale();  
  void initialize();
  void tare();
  void setWeigtLimit();
  bool weightAchieved();
};

#endif

