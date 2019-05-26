cmake_minimum_required(VERSION 3.14)
project(Invincible_ClientLogic)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE CMAKE_SOURCE_DIR)

add_executable(Invincible_ClientLogic main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})