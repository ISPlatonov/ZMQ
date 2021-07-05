#include "subscriber.hpp"

subscriber::subscriber(const char* addr)
{
    // initialize the zmq context with a single IO thread
    this->context = zmq::context_t{1};
    std::cout << "sub context made" << std::endl;

    // construct a SUB socket and connect to interface
    this->socket = zmq::socket_t{context, zmq::socket_type::sub};
    std::cout << "sub socket created" << std::endl;
    socket.setsockopt(ZMQ_SUBSCRIBE, "", std::strlen(""));
    std::cout << "sub setsockopt made" << std::endl;
    socket.connect(addr);
    std::cout << "sub socket connected" << std::endl;
}

subscriber::~subscriber()
{
    this->socket.close();
}

int subscriber::worker()
{
    zmq::message_t message;

    std::cout << "Waiting for a message..." << std::endl;

    // receive a message from the server
    this->socket.recv(message, zmq::recv_flags::none);

    student_data data = string_to_data(message.to_string());
    std::cout << "Data is formed" << std::endl;
    data.range_data();

    std::cout << "  RECEIVED:\n-----\n" << data.data_to_string() << "\n-----" << std::endl;

    return 0;
}

int main()
{
    subscriber sub;
    std::cout << "sub created" << std::endl;
    sub.worker();
    std::cout << "sub works" << std::endl;
}
