#include "SoundSensor.h"
#include <sstream>
#include <cstdlib>

float SoundSensor::simulateDecibelLevel() const {
    return 30.0f + static_cast<float>(rand()) / RAND_MAX * 70.0f;  // 30 to 100 dB
}

nlohmann::json SoundSensor::generateData() const {
    float dB = simulateDecibelLevel();
    std::stringstream ss;
    ss << "{ \"sensor\": \"" << getID() << "\", \"type\": \"sound\", \"value\": " << dB << " }";
    return ss.str();
}