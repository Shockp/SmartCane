#include "VibrationAlert.h"

VibrationAlert::VibrationAlert(int pin) {
    motorPin = pin;
    lastVibrationTime = 0;
    motorState = false;
}

void VibrationAlert::init() {
    pinMode(motorPin, OUTPUT);
    digitalWrite(motorPin, LOW);
}

void VibrationAlert::update(long distance) {
    if (distance > MAX_DISTANCE_CM) {
        digitalWrite(motorPin, LOW);
        motorState = false;
        return;
    }

    // Calculate delay based on distance
    // Distance: 0 -> Delay: MIN_VIBRATION_DELAY
    // Distance: MAX -> Delay: MAX_VIBRATION_DELAY
    long interval = map(distance, 0, MAX_DISTANCE_CM, MIN_VIBRATION_DELAY, MAX_VIBRATION_DELAY);
    interval = constrain(interval, MIN_VIBRATION_DELAY, MAX_VIBRATION_DELAY);

    unsigned long currentMillis = millis();

    if (currentMillis - lastVibrationTime >= interval) {
        lastVibrationTime = currentMillis;
        motorState = !motorState; // Toggle state
        digitalWrite(motorPin, motorState ? HIGH : LOW);
    }
}
