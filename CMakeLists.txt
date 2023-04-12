cmake_minimum_required(VERSION 3.24)
project(DB_cars_version2)

set(CMAKE_CXX_STANDARD 17)

add_executable(DB_cars_version2 main.cpp lib/model/Automaker.h lib/model/ModelCar.h lib/helper/FileHelper.h lib/helper/ConsoleHelper.h lib/Parsing.h lib/DB.h)
