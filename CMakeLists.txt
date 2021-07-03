cmake_minimum_required(VERSION 3.6)
project(main)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

message(STATUS "Generating publisher files")
add_subdirectory(publisher)

message(STATUS "Generating subscriber files")
add_subdirectory(subscriber)

install(TARGETS subscriber publisher DESTINATION ${CMAKE_BINARY_DIR}/build)
