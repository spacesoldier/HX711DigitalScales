#ifndef RELAY_MODULE_H
#define RELAY_MODULE_H

#include <Arduino.h>

class RelayModule{
private:
  static const int relayCount = 2;
  int relayPins[relayCount] = {A3,A4};
public:
  RelayModule();
  void initialize();
  
};

#endif

