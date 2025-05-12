#include "BrokerServer.h"
#include "../common/NetworkUtils.h"
#include <iostream>

using boost::asio::ip::tcp;

// io_context is the event loop manager that dispatches I/O operations (file I/O, timers, queuing async operations etc)
BrokerServer::BrokerServer(boost::asio::io_context& io_context, short port)
    : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
    doAccept();
}

void BrokerServer::doAccept() {
    auto socket = std::make_shared<tcp::socket>(acceptor_.get_executor());
    // listen for a connection; when one arrives - denoted by no error !er - enter the lambda
    // under the hood, this is event-based. The OS caches the lambda below, then triggers it once 
    // a connection is established.
    // it is recursive so there is always a handle awaiting a new connection
    acceptor_.async_accept(*socket, [this, socket](boost::system::error_code ec) {
        if (!ec) {
            std::cout << "Sensor connected!" << std::endl;
            // create a 1kb buffer to store incoming data
            auto buffer = std::make_shared<std::vector<char>>(1024);
            // reads as much data as is currently available
            socket->async_read_some(boost::asio::buffer(*buffer), [socket, buffer, this](boost::system::error_code ec, std::size_t length) {
                if (!ec) {
                    std::string data(buffer->data(), length);
                    std::cout << "Received: " << data << std::endl;
                    routeMessageToConsumers(data);
                }
            });
        }
        doAccept();
    });
}

void BrokerServer::registerConsumer(std::shared_ptr<IMessageConsumer> consumer) {
    consumers.push_back(consumer);
}

void BrokerServer::routeMessageToConsumers(const std::string& message) {
    for (const auto& c : consumers) {
        c->handleMessage(message);
    }
}
