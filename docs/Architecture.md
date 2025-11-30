# Software Architecture

The Smart Cane software follows a modular object-oriented architecture. Each hardware component is encapsulated in its own class, abstracting the low-level hardware interactions from the main logic.

## Class Diagram

```mermaid
classDiagram
    class SmartCane {
        +setup()
        +loop()
    }
    
    class DistanceSensor {
        -int trigPin
        -int echoPin
        +init()
        +getDistance() long
    }
    
    class VibrationAlert {
        -int motorPin
        -long lastVibrationTime
        -bool motorState
        +init()
        +update(long distance)
    }
    
    class GPSLocation {
        -int rxPin
        -int txPin
        -SoftwareSerial* gpsSerial
        -TinyGPSPlus gps
        +init()
        +update()
        +isValid() bool
        +getLatitude() double
        +getLongitude() double
    }
    
    class SMSCommunicator {
        -int rxPin
        -int txPin
        -SoftwareSerial* gsmSerial
        +init()
        +sendSOS(double lat, double lon)
    }
    
    class BatteryMonitor {
        -int pin
        -float voltageDividerRatio
        -float threshold
        +init()
        +getVoltage() float
        +isLow() bool
    }
    
    class EmergencyButton {
        -int pin
        -int lastState
        -unsigned long lastDebounceTime
        +init()
        +isPressed() bool
    }

    SmartCane ..> DistanceSensor : uses
    SmartCane ..> VibrationAlert : uses
    SmartCane ..> GPSLocation : uses
    SmartCane ..> SMSCommunicator : uses
    SmartCane ..> BatteryMonitor : uses
    SmartCane ..> EmergencyButton : uses
```

## Modules Description

- **Sensors**:
    - `DistanceSensor`: Handles HC-SR04 ultrasonic sensor readings.
    - `BatteryMonitor`: Reads battery voltage via a voltage divider.
    - `EmergencyButton`: Handles button input with debouncing.
- **Actuators**:
    - `VibrationAlert`: Controls the vibration motor with variable frequency based on distance.
- **Communication**:
    - `GPSLocation`: Manages the NEO6M GPS module to retrieve coordinates.
    - `SMSCommunicator`: Manages the SIM800L module to send SOS messages.
- **Config**:
    - `Config.h`: Central configuration file for pins and constants.
