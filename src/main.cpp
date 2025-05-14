#include "broker/BrokerServer.h"
#include "consumers/LoggerConsumer.h"
#include "consumers/AlertConsumer.cpp"
#include "sensors/SensorRegistryLoader.h"
#include <boost/asio/io_context.hpp>
#include <memory>
#include <iostream>

extern void StartBroker();

int main() {
    boost::asio::io_context io_context;
    short port = 12345;

    auto broker = std::make_unique<BrokerServer>(io_context, port);
    // one logging consumer handles all sensors by giving each its own thread
    // and enqueuing log requests as needed
    auto logger = std::make_shared<LoggerConsumer>("broker.log");
    broker->registerConsumer(logger);

    loadSensorRegistry("config/sensors.json");
    io_context.run();
    return 0;
}