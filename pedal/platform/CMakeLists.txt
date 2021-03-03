cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 17)
project (bpb_pedal_platform)

include_directories("include" "src" "src/platforms/${PLATFORM}")

file(GLOB SOURCES "src/*.cpp" "src/platforms/${PLATFORM}/*.cpp")

add_library(bpb_pedal_platform ${SOURCES})