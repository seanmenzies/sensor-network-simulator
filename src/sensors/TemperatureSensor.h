#pragma once
#include "SensorNodeBase.h"
#include "../config/Configuration.h"
#include <random>

class TemperatureSensor : public SensorNodeBase {
public:
    TemperatureSensor(std::string id, const std::string& host, short port, int interval)
    : SensorNodeBase(id, host, port, interval) {};
    
    std::string getCurrentTimestamp() const;

    nlohmann::json generateData() const override {
        nlohmann::json data = SensorNodeBase::generateData();
        // Simulate temperature between 20°C and 80°C
        data["temperature"] = Configuration::convertToTempUnit(20 + (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 60.f);
        return data;
    }
};