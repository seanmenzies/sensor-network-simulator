#pragma once
#include "SensorNodeBase.h"

class SoundSensor : public SensorNodeBase {
public:
    SoundSensor();

    std::string generateData() override;

private:
    float simulateDecibelLevel();  // e.g., 30–100 dB
};