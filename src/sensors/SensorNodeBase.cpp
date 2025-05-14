
#include <chrono>
#include <sstream>
#include <iostream>
#include "SensorNodeBase.h"

using json = nlohmann::json;
using boost::asio::ip::tcp;
using namespace std::chrono;

SensorNodeBase::SensorNodeBase(std::string id, const std::string& host, short port, int interval) 
    // use initializer list to assign value to const var
    : sensor_id(id),_host(host), _port(port), _interval(interval) {
    
}

void SensorNodeBase::start()
{
    // allocate a new thread and init a timer that reports
    // data to the broker at intervals defined in config
    isRunning = true;
    sensorThread = std::thread([this]() {
        while (isRunning) {
            sendToBroker();
            std::this_thread::sleep_for(std::chrono::seconds(_interval));
        }
    });
}

nlohmann::json SensorNodeBase::generateData() const
{
    json payload;

    payload["sensor_id"] = sensor_id;
    payload["sensor_type"] = static_cast<int>(getSensorType());
    payload["timestamp"] = getCurrentTimestamp();

    return payload;
}

std::string SensorNodeBase::generateSensorID_deprecated() 
{
    static boost::uuids::random_generator generator;
    // generate a random uuid
    boost::uuids::uuid id = generator();
    // init a string buffer
    std::ostringstream ss;
    // write id to buffer and return as std::string
    ss << id;
    return ss.str();
}

void SensorNodeBase::sendToBroker()
{
    // open up a socket if none exists
    if (!_socket || !_socket->is_open()) {
        // resolve the broker address
        // this converts a human readable host name or IP to socket usable endpoints
        tcp::resolver resolver(_io_context);
        auto endpoints = resolver.resolve(_host, std::to_string(_port));
        
        // loop through and try to connect to each endpoint until one succeeds, at which
        // point the socket is "connected" and the endpoint bound to the socket
        _socket = std::make_unique<boost::asio::ip::tcp::socket>(_io_context);
        boost::asio::connect(*_socket, endpoints);
    }
    nlohmann::json payload = generateData();
    // deserialise from JSON to a string then send payload to broker
    boost::asio::write(*_socket, boost::asio::buffer(payload.dump()));
}

SensorNodeBase::~SensorNodeBase()
{
    isRunning = false;
    if (sensorThread.joinable()) {
        sensorThread.join();
    }
}
