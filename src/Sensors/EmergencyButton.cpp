#include "EmergencyButton.h"

EmergencyButton::EmergencyButton(int p) {
    pin = p;
    lastState = LOW;
    lastDebounceTime = 0;
    debounceDelay = 50;
}

void EmergencyButton::init() {
    pinMode(pin, INPUT_PULLUP); // Assumes button connects to GND when pressed
}

bool EmergencyButton::isPressed() {
    int reading = digitalRead(pin);
    bool pressed = false;

    // If the switch changed, due to noise or pressing:
    if (reading != lastState) {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        // If using INPUT_PULLUP, LOW means pressed
        if (reading == LOW) {
             pressed = true;
        }
    }
    
    lastState = reading;
    return pressed;
}
