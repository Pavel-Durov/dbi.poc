cmake_minimum_required(VERSION 3.22)

set(CMAKE_BUILD_TYPE Debug)
if ("${CMAKE_BUILD_TYPE}" MATCHES "Debug")
  set(DEBUG ON)
endif ("${CMAKE_BUILD_TYPE}" MATCHES "Debug")

project(dynamorio_exp)

# Directory for dynamoRIO application config files
make_directory("dynamorio_config")

# check for DynamoRIO dependency
find_package(DynamoRIO)
if (NOT DynamoRIO_FOUND)
  message(FATAL_ERROR "dynamically package required to build")
endif(NOT DynamoRIO_FOUND)

# applications (executables)
add_executable(hello_world "src/hello_world/hello_world_app.cpp")

# dynamorio clients
add_library(hello_world_client SHARED src/hello_world/hello_world_client.cpp)
configure_DynamoRIO_client(hello_world_client)

add_library(average_bb_size_client SHARED src/average_bb_size/average_bb_size_client.cpp)
configure_DynamoRIO_client(average_bb_size_client)

