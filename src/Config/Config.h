#ifndef CONFIG_H
#define CONFIG_H

// --- Pin Definitions (Placeholders - Update when wiring is confirmed) ---

// Distance Sensor (HC-SR04)
#define PIN_TRIG 9
#define PIN_ECHO 10

// Vibration Motor
#define PIN_VIBRATION 6  // Must be a PWM pin for intensity control if needed, or just digital for pulsing

// GPS Module (NEO6M) - using SoftwareSerial
#define PIN_GPS_RX 4
#define PIN_GPS_TX 3

// GSM Module (SIM800L) - using SoftwareSerial
#define PIN_GSM_RX 7
#define PIN_GSM_TX 8

// Battery Monitor
#define PIN_BATTERY A0

// Emergency Button
#define PIN_BUTTON 2    // Interrupt capable pin recommended

// --- Constants ---

// Vibration Logic
#define MAX_DISTANCE_CM 200
#define MIN_VIBRATION_DELAY 50   // ms (fastest pulsing)
#define MAX_VIBRATION_DELAY 1000 // ms (slowest pulsing)

// Battery Logic
#define BATTERY_THRESHOLD_VOLTS 3.3 // Example threshold
#define VOLTAGE_DIVIDER_RATIO 2.0   // Adjust based on resistors used

// GPS
#define GPS_BAUD 9600

// GSM
#define GSM_BAUD 9600

#endif
