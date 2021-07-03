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

    // prepare some static data for responses
    //const std::string data{"World"};

    for (;;) 
    {
        /*
        std::string data;

        std::cout << "Type a message for publishing" << std::endl;
        //std::cin >> data;
        std::getline(std::cin, data);

        std::this_thread::sleep_for(1s);

        // send the data to the client
        socket.send(zmq::buffer(data), zmq::send_flags::none);
        std::cout << "  SENT: " << data << std::endl;
        */
        
        data_joiner::student_data data_1, data_2, result_data;

        // wrapping the data from 2 files
        data_wrapper::data_wrapper("data/student_file_1.txt", &data_1);
        data_wrapper::data_wrapper("data/student_file_2.txt", &data_2);

        // getting the intersection
        result_data = data_joiner::intersection(data_1, data_2);

        // sending the data to publishers
        /*for (auto data_line : result_data)
        {
            //std::cout << std::get<0>(data_line) << ' ' << std::get<1>(data_line) << ' ' << std::get<2>(data_line) << std::endl;

        }*/
        std::string data;
        std::cout << "Type a message for publishing" << std::endl;
        //std::cin >> data;
        std::getline(std::cin, data);

        std::string result_string = result_data.data_to_string();
        socket.send(zmq::buffer(result_string), zmq::send_flags::none);
        std::cout << "  SENT: " << result_string << std::endl;
    }

    return 0;
}
