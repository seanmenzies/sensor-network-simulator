#include "MotionSensor.h"
#include <sstream>
#include <cstdlib>


bool MotionSensor::simulateMotion() {
    return rand() % 10 == 0;  // 10% chance
}

nlohmann::json MotionSensor::generateData() const {
    /*bool motion = simulateMotion();
    std::stringstream ss;
    ss << "{ \"sensor\": \"" << getID() << "\", \"type\": \"motion\", \"value\": " << (motion ? "true" : "false") << " }";
    return ss.str();*/
    return SensorNodeBase::generateData();
}