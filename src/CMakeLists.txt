cmake_minimum_required(VERSION 3.15)
project(My_String)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES MyString.cpp MyString.h main.cpp)

add_executable(My_String_src ${SOURCE_FILES})
