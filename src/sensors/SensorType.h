#pragma once
#include <string>

enum class SensorType {
    Temperature,
    Motion,
    Sound,
    Unknown
};

SensorType sensorTypeFromInt(int value);
SensorType sensorTypeFromString(const std::string& typeStr);
std::string sensorTypeToString(SensorType type);