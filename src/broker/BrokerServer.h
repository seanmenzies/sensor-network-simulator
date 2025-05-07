#pragma once
#include <boost/asio.hpp>
#include <memory>

class BrokerServer {
public:
    BrokerServer(boost::asio::io_context& io_context, short port);

private:
    void doAccept();

    // an acceptor binds to an IP address and port
    // conditionally accepts when connection attempt received
    boost::asio::ip::tcp::acceptor acceptor_;
};