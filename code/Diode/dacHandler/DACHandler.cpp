#include <Arduino.h>
#include "DACHandler.h"

DACHandler::DACHandler(unsigned int pin) {
    this->pin = pin;
}

void DACHandler::setVoltage(unsigned int rawValue) { 
    int scaledValue = static_cast<int>((rawValue * 255.0) / 4095.0);
    dacWrite(pin,scaledValue); 
}

