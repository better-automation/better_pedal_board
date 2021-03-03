cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 17)
project (bpb_shared)

include_directories("include/data" "include/platform" "include/platform/simulator" "src/data" "src/platform" "src/platform/simulator")

file(GLOB SOURCES "src/data/*.cpp" "src/platform/*.cpp" "src/platform/simulator/*.cpp")

add_library(bpb_shared STATIC ${SOURCES})