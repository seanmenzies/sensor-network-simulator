file(GLOB SENSOR_SOURCES "*.cpp")
add_library(sensors STATIC ${SENSOR_SOURCES})
target_include_directories(sensors PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost REQUIRED COMPONENTS system)
target_link_libraries(sensors PUBLIC Boost::system)