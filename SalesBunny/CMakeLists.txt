cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "-std=c++17")

project(SalesBunny)

add_executable(
    SalesBunny
    main.cpp
    CAString.cpp
    FormValidation.cpp
)


