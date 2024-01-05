#include "phyphoxBle.h"
#include "ADCHandler.h"
#include "DACHandler.h"

unsigned int pin_dac_control = 15;
unsigned int pin1 = 35;
unsigned int pin2 = 34;
unsigned int pin_dac = 25;
float refVoltage = 3.3;

ADCHandler controlDAC(pin_dac_control, refVoltage);
ADCHandler myADC1(pin1, refVoltage);
ADCHandler myADC2(pin2, refVoltage);

DACHandler myDAC(pin_dac);

void setup() {
    Serial.begin(9600);
    PhyphoxBLE::start("kennlinie_esp32");
}

void loop() {
    int controlDACValue = controlDAC.getRawValue();
    myDAC.setVoltage(controlDACValue);
    float voltage1 = myADC1.getVoltage();
    float voltage2 = myADC2.getVoltage();
    float current = ((voltage2-voltage1)/220)*1000; 
    delay(1);
    PhyphoxBLE::write(voltage1, current);
    
    /*Serial.print(voltage1);*/
    /*Serial.print(" ");*/
    /*Serial.println(current);*/

    delay(100);
}

