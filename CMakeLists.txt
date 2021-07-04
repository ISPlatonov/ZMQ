cmake_minimum_required(VERSION 3.6)
project(main)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

#message(STATUS "Generating publisher files")
#add_subdirectory(publisher)

#message(STATUS "Generating subscriber files")
#add_subdirectory(subscriber)

#install(TARGETS subscriber publisher DESTINATION ${CMAKE_BINARY_DIR}/build)






set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp subscriber/subscriber.cpp subscriber/structure_data_maker.cpp publisher/publisher.cpp publisher/data_joiner.cpp publisher/data_wrapper.cpp)
add_executable(main ${SOURCE_FILES})
target_link_libraries(main zmq pthread)

install(TARGETS main DESTINATION ${CMAKE_BINARY_DIR}/build)

