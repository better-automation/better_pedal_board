cmake_minimum_required(VERSION 2.8.9)
set(CMAKE_CXX_STANDARD 17)
project (bpb_program_tests)

enable_testing()

include(GoogleTest)

find_package(GTest CONFIG REQUIRED)

file(GLOB SOURCES "program_service_tests/*.cpp" "../*.cpp" )

add_executable(bpb_program_tests ${SOURCES})

include_directories("program_service_tests" "../" "../../") 

target_link_libraries(bpb_program_tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

gtest_discover_tests(bpb_program_tests)