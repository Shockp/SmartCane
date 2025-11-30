#ifndef VIBRATION_ALERT_H
#define VIBRATION_ALERT_H

#include <Arduino.h>
#include "../Config/Config.h"

class VibrationAlert {
private:
    int motorPin;
    unsigned long lastVibrationTime;
    bool motorState;

public:
    VibrationAlert(int pin);
    void init();
    void update(long distance); // Call this in loop
};

#endif
