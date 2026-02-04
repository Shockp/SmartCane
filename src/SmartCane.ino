#include <Arduino.h>
#include "Config/Config.h"
#include "Sensors/DistanceSensor.h"
#include "Actuators/VibrationAlert.h"
#include "Communication/GPSLocation.h"
#include "Communication/SMSCommunicator.h"
#include "Sensors/BatteryMonitor.h"
#include "Sensors/EmergencyButton.h"

// Instantiate Modules
DistanceSensor distanceSensor(PIN_TRIG, PIN_ECHO);
VibrationAlert vibrationAlert(PIN_VIBRATION);
GPSLocation gpsLocation(PIN_GPS_RX, PIN_GPS_TX);
SMSCommunicator smsCommunicator(PIN_GSM_RX, PIN_GSM_TX);
BatteryMonitor batteryMonitor(PIN_BATTERY, VOLTAGE_DIVIDER_RATIO, BATTERY_THRESHOLD_VOLTS);
EmergencyButton emergencyButton(PIN_BUTTON);

void setup() {
    Serial.begin(9600); // For debugging
    
    distanceSensor.init();
    vibrationAlert.init();
    gpsLocation.init();
    smsCommunicator.init();
    batteryMonitor.init();
    emergencyButton.init();
    
    Serial.println("Smart Cane System Initialized");
}

void loop() {
    // 1. Update GPS
    gpsLocation.update();

    // 2. Check Emergency Button
    if (emergencyButton.isPressed()) {
        Serial.println("Emergency Button Pressed!");
        if (gpsLocation.isValid()) {
            smsCommunicator.sendSOS(gpsLocation.getLatitude(), gpsLocation.getLongitude());
        } else {
            Serial.println("GPS Invalid, sending last known or 0,0");
            // Optionally send 0,0 or wait
            smsCommunicator.sendSOS(0.0, 0.0); 
        }
        delay(5000); // Prevent spamming
    }

    // 3. Distance & Vibration
    long distance = distanceSensor.getDistance();
    vibrationAlert.update(distance);

    // 4. Battery Check
    if (batteryMonitor.isLow()) {
        Serial.println("Battery Low!");
    }

    delay(10); // Small delay for stability
}
