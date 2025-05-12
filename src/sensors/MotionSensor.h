#pragma once
#include "SensorNodeBase.h"

class MotionSensor : public SensorNodeBase {
public:
    nlohmann::json generateData() const override;

private:
    bool simulateMotion();  // returns true or false
};