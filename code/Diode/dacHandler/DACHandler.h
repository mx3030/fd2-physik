#ifndef DAC_HANDLER_H
#define DAC_HANDLER_H

class DACHandler {
public:
    DACHandler(unsigned int pin);
    void setVoltage(unsigned int rawValue);

private:
    unsigned int pin;
};

#endif
