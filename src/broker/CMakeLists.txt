add_library(broker STATIC BrokerServer.cpp)

find_package(Boost REQUIRED COMPONENTS system)
target_link_libraries(broker PUBLIC Boost::system)
