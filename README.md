# Smart Cane Project

This repository contains the software implementation for a Smart Cane designed for visually impaired users. It features obstacle detection, GPS tracking, and emergency SOS messaging.

## Features
- **Obstacle Detection**: Ultrasonic sensor detects objects up to 2 meters.
- **Haptic Feedback**: Vibration motor pulses faster as objects get closer.
- **Emergency SOS**: Button press sends SMS with GPS coordinates.
- **Battery Monitoring**: Alerts when battery is low.

## Repository Structure

```
BastonInteligente/
├── docs/               # Documentation
│   ├── Architecture.md # UML Class Diagram & Architecture details
│   └── UseCases.md     # UML Use Case Diagram & Descriptions
├── src/                # Source Code
│   ├── Actuators/      # Output modules (Vibration)
│   ├── Communication/  # Comms modules (GPS, GSM)
│   ├── Config/         # Configuration files
│   └── Sensors/        # Input modules (Distance, Battery, Button)
├── SmartCane.ino       # Main Arduino Sketch
└── README.md           # This file
```

## Getting Started
1. Open `SmartCane.ino` in Arduino IDE.
2. Install required libraries: `TinyGPS++`.
3. Check `src/Config/Config.h` to verify pin assignments match your wiring.
4. Upload to your Arduino board.

## Hardware
- Arduino (Uno/Nano)
- HC-SR04 Ultrasonic Sensor
- NEO6M GPS Module
- SIM800L GSM Module
- Vibration Motor
- Push Button
- Battery & Voltage Divider
