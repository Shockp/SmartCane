#ifndef DISTANCE_SENSOR_H
#define DISTANCE_SENSOR_H

#include <Arduino.h>

class DistanceSensor {
private:
    int trigPin;
    int echoPin;

public:
    DistanceSensor(int trig, int echo);
    void init();
    long getDistance(); // Returns distance in cm
};

#endif
