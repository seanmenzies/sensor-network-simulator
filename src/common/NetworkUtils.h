#pragma once
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std::chrono;

void sendDataToBroker(const std::string& host, short port, const std::string& message);

std::string getCurrentTimestamp();