cmake_minimum_required(VERSION 3.21)
project(UKlausur)

set(CMAKE_CXX_STANDARD 14)

add_executable(UKlausur main.cpp Logic.cpp Logic.h MetaData.cpp MetaData.h ReadSaveInterface.h)
