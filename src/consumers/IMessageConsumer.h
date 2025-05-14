#pragma once
#include <string>

class IMessageConsumer {
public:
    virtual void handleMessage(const std::string& message) = 0;
    virtual ~IMessageConsumer() = default;
};