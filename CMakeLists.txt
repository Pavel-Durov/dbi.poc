cmake_minimum_required(VERSION 3.22)

set(CMAKE_BUILD_TYPE Debug)

project(hello_world)

# compilers set
SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)

# debug mode
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

# Directory for dynamoRIO application config files
make_directory("dynamorio_config")

# check for DynamoRIO dependency
find_package(DynamoRIO)
if (NOT DynamoRIO_FOUND)
  message(FATAL_ERROR "dynamically package required to build")
endif(NOT DynamoRIO_FOUND)

function (add_client name file_source)
  add_library(hello_world_client SHARED ${file_source})
  configure_DynamoRIO_client(hello_world_client)
endfunction (add_client)

# dynamorio clients
add_client(hello_world_client "src/hello_world/hello_world_client.cpp")

# executables
add_executable(hello_world "src/hello_world/hello_world_app.cpp")
