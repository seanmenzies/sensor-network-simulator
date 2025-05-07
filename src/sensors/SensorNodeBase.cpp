#include <boost/asio.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sstream>
#include <iostream>
#include "SensorNodeBase.h"

SensorNodeBase::SensorNodeBase() 
    // use initializer list to assign value to const var
    : sensor_id(generateSensorID()) {
    
}

std::string SensorNodeBase::generateSensorID() {
    static boost::uuids::random_generator generator;
    // generate a random uuid
    boost::uuids::uuid id = generator();
    // init a string buffer
    std::ostringstream ss;
    // write id to buffer and return as std::string
    ss << id;
    return ss.str();
}

void SensorNodeBase::sendToBroker(const std::string &host, short port, const std::string &message)
{
    try {
        boost::asio::io_context io_context;

        boost::asio::ip::tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(host, std::to_string(port));

        boost::asio::ip::tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        boost::asio::write(socket, boost::asio::buffer(message));
    } catch (std::exception& e) {
        std::cerr << "Sensor failed to send: " << e.what() << std::endl;
    }
}
