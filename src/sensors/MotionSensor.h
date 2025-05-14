#pragma once
#include "SensorNodeBase.h"

class MotionSensor : public SensorNodeBase {
public:
    MotionSensor(std::string id, const std::string& host, short port, int interval)
    : SensorNodeBase(id, host, port, interval) {}
    nlohmann::json generateData() const override;

private:
    bool simulateMotion() const;  // returns true or false
};