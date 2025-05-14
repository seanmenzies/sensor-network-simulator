#pragma once
#include "../common/NetworkUtils.h"
#include <boost/asio.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <string>
#include <chrono>
#include <thread>
#include <atomic>
#include <nlohmann/json.hpp>

class SensorNodeBase {
public:
    SensorNodeBase(std::string id, const std::string& host, short port, int interval);
    virtual ~SensorNodeBase();

    virtual void start();

    // simulate data and return as string
    virtual nlohmann::json generateData() const;

    // get sensor ID
    std::string getID() const { return sensor_id; }

protected:
    const std::string sensor_id;
    virtual ESensorType getSensorType() const = 0;
    const std::string _host;
    const short _port;
    const int _interval;

    std::thread sensorThread;
    std::atomic<bool> isRunning = false;

    std::unique_ptr<boost::asio::ip::tcp::socket> _socket;
    boost::asio::io_context _io_context;

private:
    std::string generateSensorID_deprecated();
    void sendToBroker();
};