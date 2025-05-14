#include "SensorRegistryLoader.h"
#include "SensorType.h"
#include "SensorManager.h"
#include "TemperatureSensor.h"
#include "MotionSensor.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>

void loadSensorRegistry(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "[RegistryLoader] Failed to open: " << filePath << std::endl;
        return;
    }

    nlohmann::json registry;
    file >> registry;

    for (const auto& entry : registry) {
        std::string id = entry["sensor_id"];
        int typeCode = entry["sensor_type"];
        int interval = entry["sampling_interval"];
        std::string host = entry["broker_host"];
        short port = entry["broker_port"];

        SensorType type = sensorTypeFromInt(typeCode);
        switch (type) {
            case SensorType::Temperature: {
                auto sensor = std::make_shared<TemperatureSensor>(id, host, port, interval);
                SensorManager::get()->addNewSensor(sensor);
                sensor->start();
                break;
            }
            case SensorType::Motion: {
                auto sensor = std::make_shared<MotionSensor>(id, host, port, interval);
                SensorManager::get()->addNewSensor(sensor);
                sensor->start();
                break;
            }
            default:
                std::cerr << "[RegistryLoader] Unknown sensor type: " << typeCode << std::endl;
                break;
        }
    }
}