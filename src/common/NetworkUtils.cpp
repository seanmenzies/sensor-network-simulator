#include "NetworkUtils.h"
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;
using namespace std::chrono;

void sendDataToBroker(const std::string &host, short port, const std::string &message)
{
    try {
        boost::asio::io_context io_context;

        // resolve the broker address
        // this converts a human readable host name or IP to socket usable endpoints
        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve(host, std::to_string(port));

        // loop through and try to connect to each endpoint until one succeeds, at which
        // point the socket is "connected" and the endpoint bound to the socket
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        // send the message
        boost::asio::write(socket, boost::asio::buffer(message));

    } catch (std::exception& e) {
        std::cerr << "Failed to send sensor data: " << e.what() << std::endl;
    }
}

