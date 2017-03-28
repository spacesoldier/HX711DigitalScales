#include "relay_module.h"

RelayModule::RelayModule(){
  
}

void RelayModule::initialize(){
  for (int i = 0; i<relayCount; i++){
    pinMode(relayPins[i],OUTPUT);
  }
}

