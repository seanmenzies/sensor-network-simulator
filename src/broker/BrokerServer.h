#pragma once
#include "../consumers/IMessageConsumer.h"
#include <vector>
#include <memory>
#include <boost/asio.hpp>
#include <memory>

class BrokerServer {
public:
    BrokerServer(boost::asio::io_context& io_context, short port);

    void registerConsumer(std::shared_ptr<class ConsumerBase> consumer);

private:
    void doAccept();
    std::vector<std::shared_ptr<class ConsumerBase>> consumers;
    void routeMessageToConsumers(const std::string& message);

    // an acceptor binds to an IP address and port
    // conditionally accepts when connection attempt received
    boost::asio::ip::tcp::acceptor acceptor_;
};