#pragma once

#include <string>
//#include <chrono>
#include <thread>
#include <iostream>

#include <zmq.hpp>

#include "structure_data_maker.hpp"

class subscriber
{
public:
    subscriber(const char* addr="tcp://172.17.0.1:5555");

    // receive a message
    int worker();
    ~subscriber();
private:
    zmq::socket_t socket;
    zmq::context_t context;
};
