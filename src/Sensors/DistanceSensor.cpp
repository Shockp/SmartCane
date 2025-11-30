#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(int trig, int echo) {
    trigPin = trig;
    echoPin = echo;
}

void DistanceSensor::init() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

long DistanceSensor::getDistance() {
    // Clear the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Set the trigPin on HIGH for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Read the echoPin, returns the sound wave travel time in microseconds
    long duration = pulseIn(echoPin, HIGH, 30000); // Timeout 30ms (~5m)
    
    if (duration == 0) return 999; // No echo or out of range
    
    // Calculate the distance
    long distance = duration * 0.034 / 2;
    
    return distance;
}
