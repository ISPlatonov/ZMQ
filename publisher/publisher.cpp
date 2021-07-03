#include <string>
#include <chrono>
#include <thread>
#include <iostream>

#include <zmq.hpp>

#include "data_wrapper.hpp"

int main() 
{
    using namespace std::chrono_literals;

    // initialize the zmq context with a single IO thread
    zmq::context_t context{1};

    // construct a REP (reply) socket and bind to interface
    zmq::socket_t socket{context, zmq::socket_type::pub};
    socket.bind("tcp://*:5555");

    for (;;) 
    {        
        data_joiner::student_data data_1, data_2, result_data;

        // wrapping the data from 2 files
        data_wrapper::data_wrapper("data/student_file_1.txt", &data_1);
        data_wrapper::data_wrapper("data/student_file_2.txt", &data_2);

        // getting the intersection
        result_data = data_joiner::intersection(data_1, data_2);

        // sending the data to publishers
        std::string data;
        std::cout << "Type any message for publishing the data" << std::endl;
        std::getline(std::cin, data);

        std::string result_string = result_data.data_to_string();
        socket.send(zmq::buffer(result_string), zmq::send_flags::none);
        std::cout << "  SENT:\n-----\n" << result_string << "\n-----" << std::endl;
    }

    return 0;
}
