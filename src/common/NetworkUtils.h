#pragma once
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std::chrono;

enum ESensorType
{
    SENSOR_NULL,
    SENSOR_Temperature,
    SENSOR_Sound,
    SENSOR_Motion
};

void sendDataToBroker(const std::string& host, short port, const std::string& message);

std::string getCurrentTimestamp();