#ifndef DIGITAL_SCALE_H
#define DIGITAL_SCALE_H

#include <Arduino.h>
#include "HX711.h"
#include "callable.h"
#include "dataprovider.h"

class DigitalScale: public DataProvider{

private:
  uint8_t HX711_DOUT = A2;
  uint8_t HX711_PD_SCK = A1;
  
  HX711 scale;    // parameter "gain" is ommited; the default value 128 is used by the library

  double currWeight;
  double delta;
  double needWeight;

  int period;

  enum ScaleState{
    STANDBY,
    AWAIT_TARE,
    AWAIT_WEIGHT,
    GOT_WEIGHT
  };
  uint8_t state;

  Callable* handler;

  void readWeight();
  bool weightAchieved();
  void notifyHandler();
public:
  DigitalScale();  
  void initialize();
  void tare();
  void setWeigtLimit(double);
  void setPeriod(int);
  int getPeriod();
  void checkState();
  void setHandler(Callable*);
  double getData();
  void setData(double);
};

#endif

