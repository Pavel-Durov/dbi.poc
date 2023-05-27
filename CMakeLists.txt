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

function (add_sample_client name source_file_list extension_list)
  add_library(${name} SHARED ${source_file_list})
  configure_DynamoRIO_client(${name})
  foreach (ext ${extension_list})
    use_DynamoRIO_extension(${name} ${ext})
  endforeach (ext)

  # Provide a hint for how to use the client
  if (NOT DynamoRIO_INTERNAL OR NOT "${CMAKE_GENERATOR}" MATCHES "Ninja")
    DynamoRIO_get_full_path(path ${name} "${location_suffix}")
    add_custom_command(TARGET ${name}
      POST_BUILD
      COMMAND ${CMAKE_COMMAND}
      ARGS -E echo "Usage: pass to drconfig or drrun: -c ${path}"
      VERBATIM)
  endif ()

  get_property(sample_list GLOBAL PROPERTY DynamoRIO_sample_list) # NON-PUBLIC
  set_property(GLOBAL PROPERTY DynamoRIO_sample_list              # NON-PUBLIC
    "${sample_list};${name}")                                     # NON-PUBLIC
  set(srcs ${srcs} ${source_file_list} PARENT_SCOPE)              # NON-PUBLIC
  set(tgts ${tgts} ${name} PARENT_SCOPE)                          # NON-PUBLIC
  if (BUILD_TESTS)                                                # NON-PUBLIC
    add_library(${name}_test SHARED ${source_file_list})          # NON-PUBLIC
    configure_DynamoRIO_client(${name}_test)                      # NON-PUBLIC
    foreach (ext ${extension_list})                               # NON-PUBLIC
      use_DynamoRIO_extension(${name}_test ${ext})                # NON-PUBLIC
    endforeach (ext)                                              # NON-PUBLIC
    target_compile_definitions(${name}_test PRIVATE -DSHOW_RESULTS)    # NON-PUBLIC
    set(tgts ${tgts} ${name}_test PARENT_SCOPE)                        # NON-PUBLIC
  endif ()                                                             # NON-PUBLIC
endfunction (add_sample_client)


# dynamorio client
add_sample_client(hello_world_client "src/hello_world/hello_world_client.cpp" "")

# executables
add_executable(hello_world "src/hello_world/hello_world_app.cpp")
