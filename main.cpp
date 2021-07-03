#include <string>
#include <chrono>
#include <thread>
#include <iostream>

#include <zmq.hpp>

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
        std::string data;

        std::cout << "Type a message for publishing" << std::endl;
        //std::cin >> data;
        std::getline(std::cin, data);

        std::this_thread::sleep_for(1s);

        // send the data to the client
        socket.send(zmq::buffer(data), zmq::send_flags::none);
        std::cout << "  SENT: " << data << std::endl;
    }

    return 0;
}
