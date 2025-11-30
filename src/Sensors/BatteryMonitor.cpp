#include "BatteryMonitor.h"

BatteryMonitor::BatteryMonitor(int p, float ratio, float thresh) {
    pin = p;
    voltageDividerRatio = ratio;
    threshold = thresh;
}

void BatteryMonitor::init() {
    pinMode(pin, INPUT);
}

float BatteryMonitor::getVoltage() {
    int sensorValue = analogRead(pin);
    float voltage = sensorValue * (5.0 / 1023.0); // Convert to 0-5V
    return voltage * voltageDividerRatio; // Convert to actual battery voltage
}

bool BatteryMonitor::isLow() {
    return getVoltage() < threshold;
}
