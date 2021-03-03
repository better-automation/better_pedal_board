cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 17)
project (bpb_pedal)

add_subdirectory("device")
add_subdirectory("platform")
add_subdirectory("../shared" shared)

file(GLOB SOURCES "pedal/src/*.cpp")

add_executable(bpb_pedal ${SOURCES})

target_link_libraries(bpb_pedal PRIVATE bpb_pedal_device)
target_link_libraries(bpb_pedal PRIVATE bpb_pedal_platform)
target_link_libraries(bpb_pedal PRIVATE bpb_shared)