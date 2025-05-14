#include "SensorType.h"

SensorType sensorTypeFromInt(int value) {
    switch (value) {
        case 0: return SensorType::Temperature;
        case 1: return SensorType::Motion;
        case 2: return SensorType::Sound;
        default: return SensorType::Unknown;
    }
}

SensorType sensorTypeFromString(const std::string& typeStr) {
    if (typeStr == "TemperatureSensor") return SensorType::Temperature;
    if (typeStr == "MotionSensor") return SensorType::Motion;
    if (typeStr == "SoundSensor") return SensorType::Sound;
    return SensorType::Unknown;
}

std::string sensorTypeToString(SensorType type) {
    switch (type) {
        case SensorType::Temperature: return "TemperatureSensor";
        case SensorType::Motion: return "MotionSensor";
        case SensorType::Sound: return "SoundSensor";
        default: return "Unknown";
    }
}