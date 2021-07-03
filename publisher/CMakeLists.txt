cmake_minimum_required(VERSION 3.6)
project(publisher)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build)

set(SOURCE_FILES publisher.cpp data_wrapper.cpp data_joiner.cpp)
add_executable(publisher ${SOURCE_FILES})
target_link_libraries(publisher zmq)

install(TARGETS publisher DESTINATION ${CMAKE_BINARY_DIR}/../build)
