cmake_minimum_required(VERSION 3.22)

set(CMAKE_BUILD_TYPE Debug)
if ("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
  set(DEBUG ON)
endif ("${CMAKE_BUILD_TYPE}" MATCHES "Debug")

project(client)

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin/)

add_library(client SHARED ./src/client.cpp)

find_package(DynamoRIO)
if (NOT DynamoRIO_FOUND)
  message(FATAL_ERROR "dynamically package required to build")
endif(NOT DynamoRIO_FOUND)

set(DynamoRIO_SET_PREFERRED_BASE ON)

configure_DynamoRIO_client(client)
