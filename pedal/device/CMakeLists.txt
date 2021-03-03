cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 17)
project (bpb_pedal_device)

find_package(nlohmann_json CONFIG REQUIRED)

include_directories("include" "src" "src/data" "src/data/models" "src/source_devices" "src/target_devices")

file(GLOB SOURCES "src/*.cpp" "src/data/*.cpp" "src/data/models/*.cpp" "src/source_devices/*.cpp" "src/target_devices/*.cpp")

add_library(bpb_pedal_device ${SOURCES})

target_link_libraries(bpb_pedal_device PRIVATE nlohmann_json)