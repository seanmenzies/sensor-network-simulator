#include <boost/asio.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "../common/NetworkUtils.h"
#include <sstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "SensorNodeBase.h"

using json = nlohmann::json;

SensorNodeBase::SensorNodeBase() 
    // use initializer list to assign value to const var
    : sensor_id(generateSensorID()) {
    
}

std::string SensorNodeBase::generateData() const
{
    json payload;

    payload["sensor_id"] = sensor_id;
    payload["sensor_type"] = getSensorType();
    payload["timestamp"] = getCurrentTimestamp();

    // include subclass-specific data
    payload["data"] = json::parse(getSensorReadingJSON());

    return payload.dump();
}

std::string SensorNodeBase::generateSensorID() 
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

void SensorNodeBase::sendToBroker(const std::string &host, short port, const std::string &message)
{
    std::string payload = generateData();
    sendDataToBroker("127.0.0.1", 12345, payload);
}
