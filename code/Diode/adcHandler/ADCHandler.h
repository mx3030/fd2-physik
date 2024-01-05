#ifndef ADC_HANDLER_H
#define ADC_HANDLER_H

class ADCHandler {
public:
    ADCHandler(unsigned int pin, float refVoltage);
    int getRawValue();
    float getVoltage();

private:
    unsigned int pin;
    float refVoltage;
    int rawValue;
    float voltage;
};

#endif
