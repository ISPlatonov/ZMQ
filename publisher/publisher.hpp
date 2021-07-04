#pragma once

#include <string>
//#include <chrono>
#include <thread>
#include <iostream>

#include <zmq.hpp>

#include "data_wrapper.hpp"

class publisher
{
public:
    publisher(const char* addr="tcp://*:5555");

    // special method for joining 2 tables
    // and sending them to subscribers
    int worker(const std::string& path_to_data);
    ~publisher();
private:
    zmq::socket_t socket;
    zmq::context_t context;
};
