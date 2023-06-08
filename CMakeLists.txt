cmake_minimum_required(VERSION 3.22)

set(CMAKE_BUILD_TYPE Debug)

project(dynamorio_exp)

# compilers set
SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)

# debug mode
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

# Directory for dynamoRIO application config files
make_directory("dynamorio_config")

# check for DynamoRIO dependency
find_package(DynamoRIO)
if (NOT DynamoRIO_FOUND)
  message(FATAL_ERROR "dynamically package required to build")
endif(NOT DynamoRIO_FOUND)

function (add_client name source_file_list)
  add_library(${name} SHARED ${source_file_list})
  configure_DynamoRIO_client(${name})
endfunction (add_client)

# set the global vars ahead of time
configure_DynamoRIO_global(OFF ON)

# dynamorio clients
add_client("hello_world_client" "src/hello_world/hello_world_client.cpp")
add_client("average_bb_size_client" "src/average_bb_size/average_bb_size_client.cpp")
add_client("inc2add_client" "src/inc2add/inc2add_client.cpp")
use_DynamoRIO_extension("inc2add_client" "drreg")

# executables
add_executable(hello_world "src/hello_world/hello_world_app.cpp")
add_executable(inc2add_app "src/inc2add/inc2add_app.cpp")
