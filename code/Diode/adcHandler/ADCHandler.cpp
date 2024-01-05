#include <Arduino.h>
#include "ADCHandler.h"

ADCHandler::ADCHandler(unsigned int pin, float refVoltage) {
    this->pin = pin;
    this->refVoltage = refVoltage;
    this->rawValue = 0;
}

int ADCHandler::getRawValue() {
    rawValue = analogRead(pin);
    return rawValue;
}

float ADCHandler::getVoltage() { 
    rawValue = analogRead(pin);
    voltage = rawValue*(refVoltage/4095); 
    return voltage; 
}

