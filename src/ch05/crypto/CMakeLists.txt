cmake_minimum_required(VERSION 3.16)
project(crypto VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDAR_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

set(HEADER FILES
    crypto.h
)
set(SOURCES 
    crypto.cpp
    cryptoclient.cpp
)

qt_add_executable(crypto ${SOURCES})

