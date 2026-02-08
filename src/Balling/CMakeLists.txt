cmake_minimum_required(VERSION 4.1)
project(Balling)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib CONFIG REQUIRED)
find_package(asio CONFIG REQUIRED)

add_executable(Balling main.cpp)

target_link_libraries(Balling PRIVATE raylib asio)
