#pragma once
#include <string>
#include <chrono>

class SensorNodeBase {
public:
    SensorNodeBase();
    virtual ~SensorNodeBase() = default;

    // simulate data and return as string
    virtual std::string generateData() = 0;

    // get sensor ID
    std::string getID() const { return sensor_id; }

protected:
    const std::string sensor_id;

private:
    std::string generateSensorID();
    void sendToBroker(const std::string& host, short port, const std::string& message);
};