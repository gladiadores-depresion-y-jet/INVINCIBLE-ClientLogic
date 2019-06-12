cmake_minimum_required(VERSION 3.13.2)
project(Invincible_ClientLogic)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE CMAKE_SOURCE_DIR)

add_executable(Invincible_ClientLogic main.cpp client/Requests.cpp client/Requests.h synthaxParser/Parser.cpp synthaxParser/Parser.h client/ResourceOfRequest.h)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} curl)
