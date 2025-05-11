cmake_minimum_required(VERSION 3.10)
project(SensorNetworkSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_subdirectory(src/broker)
add_subdirectory(src/consumers)
add_subdirectory(src/sensors)
add_subdirectory(src/common)
add_subdirectory(src/security)
add_subdirectory(tests)

find_package(nlohmann_json REQUIRED)
target_link_libraries(nlohmann_json::nlohmann_json)
add_executable(sensor_sim src/main.cpp)
target_link_libraries(sensor_sim broker consumers)
