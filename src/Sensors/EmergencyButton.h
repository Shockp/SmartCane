#ifndef EMERGENCY_BUTTON_H
#define EMERGENCY_BUTTON_H

#include <Arduino.h>

class EmergencyButton {
private:
    int pin;
    int lastState;
    unsigned long lastDebounceTime;
    unsigned long debounceDelay;

public:
    EmergencyButton(int pin);
    void init();
    bool isPressed(); // Returns true on rising edge (press)
};

#endif
