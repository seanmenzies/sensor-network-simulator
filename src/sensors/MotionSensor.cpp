#include "MotionSensor.h"
#include <string>
#include <cstdlib>


bool MotionSensor::simulateMotion() const {
    return rand() % 10 == 0;  // 10% chance
}

nlohmann::json MotionSensor::generateData() const {
    nlohmann::json data = SensorNodeBase::generateData();
    data["simulate_motion"] = simulateMotion() ? std::string("true") : std::string("false");
    return data;
}