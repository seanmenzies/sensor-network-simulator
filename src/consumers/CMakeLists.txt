file(GLOB CONSUMER_SOURCES "*.cpp")
add_library(consumers STATIC ${CONSUMER_SOURCES})

target_link_libraries(consumers PUBLIC config)
target_include_directories(consumers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})