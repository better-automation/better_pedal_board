cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 17)
project (bpb_brain)

add_subdirectory("clock")
add_subdirectory("program")
add_subdirectory("platform")
add_subdirectory("../shared" shared)

file(GLOB SOURCES "brain/src/*.cpp")

add_executable(bpb_brain ${SOURCES})

target_link_libraries(bpb_brain PRIVATE bpb_brain_clock)
target_link_libraries(bpb_brain PRIVATE bpb_brain_program)
target_link_libraries(bpb_brain PRIVATE bpb_brain_platform)
target_link_libraries(bpb_brain PRIVATE bpb_shared)