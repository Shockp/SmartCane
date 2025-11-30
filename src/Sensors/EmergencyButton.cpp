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
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:

        // If using INPUT_PULLUP, LOW means pressed
        if (reading == LOW) {
             pressed = true;
        }
    }
    
    // Simple state check for now, can be improved for edge detection
    // For this project, returning true while held is fine, or we can add edge logic.
    // Let's stick to simple "is currently pressed" logic but filtered.
    
    lastState = reading;
    return pressed;
}
