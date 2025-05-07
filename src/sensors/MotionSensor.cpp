#include "MotionSensor.h"
#include <sstream>
#include <cstdlib>

MotionSensor::MotionSensor() : SensorNodeBase() {}

bool MotionSensor::simulateMotion() {
    return rand() % 10 == 0;  // 10% chance
}

std::string MotionSensor::generateData() {
    bool motion = simulateMotion();
    std::stringstream ss;
    ss << "{ \"sensor\": \"" << getID() << "\", \"type\": \"motion\", \"value\": " << (motion ? "true" : "false") << " }";
    return ss.str();
}