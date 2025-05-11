#pragma once
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std::chrono;

void sendDataToBroker(const std::string& host, short port, const std::string& message);

std::string getCurrentTimestamp() {
    auto now = system_clock::now();
    std::time_t now_time = system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}