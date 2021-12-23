cmake_minimum_required(VERSION 3.15)
project(My_String)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "--coverage" )
set(SOURCE_FILES MyStringTest.cpp)
set(Boost_DEBUG ON)

find_package (Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(../Src)

add_executable (Boost_Tests_run ${SOURCE_FILES})

target_link_libraries (Boost_Tests_run Boost::unit_test_framework)

