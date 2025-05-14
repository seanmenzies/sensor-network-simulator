#pragma once
#include "SensorNodeBase.h"

class SoundSensor : public SensorNodeBase {
public:
    SoundSensor(std::string id, const std::string& host, short port, int interval)
    : SensorNodeBase(id, host, port, interval) {};

    nlohmann::json generateData() const override;

private:
    float simulateDecibelLevel() const;  // e.g., 30–100 dB
};