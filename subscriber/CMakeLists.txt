cmake_minimum_required(VERSION 3.6)
project(subscriber)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../build)

set(SOURCE_FILES subscriber.cpp structure_data_maker.cpp)
add_executable(subscriber ${SOURCE_FILES})
target_link_libraries(subscriber zmq)

install(TARGETS subscriber DESTINATION ${CMAKE_BINARY_DIR}/../build)
