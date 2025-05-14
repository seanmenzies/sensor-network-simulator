#pragma once
#include "IMessageConsumer.h"
#include <fstream>
#include <string>
#include <optional>
#include <nlohmann/json.hpp>

class ConsumerBase {
public:
    virtual void handleMessage(const std::string& message) = 0;
    virtual std::optional<nlohmann::json> parseSensorMessage(const std::string& raw) = 0;
};