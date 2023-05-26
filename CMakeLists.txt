cmake_minimum_required(VERSION 3.22)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
set(DEBUG ON)

project(hello_world)

# Directory for dynamoRIO application config files
make_directory("dynamorio_config")

# check for DynamoRIO dependency
find_package(DynamoRIO)
if (NOT DynamoRIO_FOUND)
  message(FATAL_ERROR "dynamically package required to build")
endif(NOT DynamoRIO_FOUND)

# hello world
add_library(hello_world_client SHARED src/hello_world/hello_world_client.cpp)

configure_DynamoRIO_client(hello_world_client)

add_executable(hello_world "src/hello_world/hello_world_app.cpp")
