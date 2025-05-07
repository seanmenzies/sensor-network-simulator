#pragma once
#include "SensorNodeBase.h"

class MotionSensor : public SensorNodeBase {
public:
    MotionSensor();

    std::string generateData() override;

private:
    bool simulateMotion();  // returns true or false
};