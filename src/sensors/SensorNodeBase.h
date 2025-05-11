#pragma once

#include <string>
#include <chrono>

class SensorNodeBase {
public:
    SensorNodeBase();
    virtual ~SensorNodeBase() = default;

    virtual void start() {};

    // simulate data and return as string
    virtual std::string generateData() const;

    // get sensor ID
    std::string getID() const { return sensor_id; }

protected:
    const std::string sensor_id;
    virtual std::string getSensorType() const = 0;
    virtual std::string getSensorReadingJSON() const = 0;

private:
    std::string generateSensorID();
    void sendToBroker(const std::string& host, short port, const std::string& message);
};