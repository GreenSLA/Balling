cmake_minimum_required(VERSION 4.1)
project(Balling)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib CONFIG REQUIRED)
find_package(asio CONFIG REQUIRED)

add_executable(Balling main.cpp
        Global.h
        Constants.h
        WindowHelper.h
        WindowHelper.cpp
        Player.h
        PlayerHelper.cpp
        PlayerHelper.h)

target_link_libraries(Balling PRIVATE raylib asio)
