# Step 1: Collect all .cpp source files
file(GLOB COMMON_SOURCES "*.cpp")

# Step 2: Create a static library target named "common"
add_library(common STATIC ${COMMON_SOURCES})

# Step 3: Make its headers accessible to other targets
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Step 4: Link Boost.System if common code (e.g. NetworkUtils.cpp) uses Boost.Asio
find_package(Boost REQUIRED COMPONENTS system)
target_link_libraries(common PUBLIC Boost::system)