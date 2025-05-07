#include "NetworkUtils.h"
#include <boost/asio.hpp>
#include <iostream>

void sendDataToBroker(const std::string &host, short port, const std::string &message)
{
    try {
        boost::asio::io_context io_context;

        // Resolve the broker address
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(host, std::to_string(port));

        // Create and connect the socket
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        // Send the message
        boost::asio::write(socket, boost::asio::buffer(message));

    } catch (std::exception& e) {
        std::cerr << "Failed to send sensor data: " << e.what() << std::endl;
    }
}