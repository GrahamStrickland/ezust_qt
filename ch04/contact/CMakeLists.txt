cmake_minimum_required(VERSION 3.16)
project(contact VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDAR_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()

set(HEADER FILES
    contact.h
    contactfactory.h
    contactlist.h
)
set(SOURCES 
    contact.cpp
    contactfactory.cpp
    contactlist.cpp
    testcontact.cpp
)

qt_add_executable(contact ${SOURCES})

