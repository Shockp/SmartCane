#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H

#include <Arduino.h>

class BatteryMonitor {
private:
    int pin;
    float voltageDividerRatio;
    float threshold;

public:
    BatteryMonitor(int pin, float ratio, float threshold);
    void init();
    float getVoltage();
    bool isLow();
};

#endif
