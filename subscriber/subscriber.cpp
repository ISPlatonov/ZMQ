#include <string>
#include <chrono>
#include <thread>
#include <iostream>

#include <zmq.hpp>

#include "structure_data_maker.hpp"

int main() 
{
    using namespace std::chrono_literals;

    // initialize the zmq context with a single IO thread
    zmq::context_t context{1};

    // construct a SUB socket and connect to interface
    zmq::socket_t socket{context, zmq::socket_type::sub};
    socket.setsockopt(ZMQ_SUBSCRIBE, "", std::strlen(""));
    socket.connect("tcp://localhost:5555");

    // prepare some static data for sendings
    const std::string data{"Hello"};

    std::this_thread::sleep_for(1s);

    for (;;) 
    {
        zmq::message_t message;

        std::cout << "Waiting for a message..." << std::endl;

        // receive a message from the server
        socket.recv(message, zmq::recv_flags::none);

        student_data data = string_to_data(message.to_string());
        std::cout << "Data is formed" << std::endl;
        data.range_data();

        std::cout << "  RECEIVED:\n-----\n" << data.data_to_string() << "\n-----" << std::endl;
    }

    return 0;
}
