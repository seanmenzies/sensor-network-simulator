#pragma once
#include "SensorNodeBase.h"
#include "../config/Configuration.h"
#include <random>
#include <sstream>

class TemperatureSensor : public SensorNodeBase {
public:
    TemperatureSensor();
    std::string getCurrentTimestamp() const;

    std::string generateData() const override {
        // Simulate temperature between 20°C and 80°C
        float temp = Configuration::convertToTempUnit(20 + (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 60.f);
        std::ostringstream oss;
        oss << "{ \"sensor\": \"" << sensor_id << "\", \"type\": \"temperature\", \"value\": " << temp << " }";
        return oss.str();
    }
};