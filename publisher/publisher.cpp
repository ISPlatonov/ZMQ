#include "publisher.hpp"

int publisher::worker(const std::string& path_to_data)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));

    data_joiner::student_data data_1, data_2, result_data;

    // wrapping the data from 2 files
    data_wrapper::data_wrapper(path_to_data + "/" + "student_file_1.txt", &data_1);
    data_wrapper::data_wrapper(path_to_data + "/" + "student_file_2.txt", &data_2);
    std::cout << "Data wrapped" << std::endl;

    // getting the intersection
    result_data = data_joiner::intersection(data_1, data_2);

    // sending the data to publishers
    std::string result_string = result_data.data_to_string();
    this->socket.send(zmq::buffer(result_string), zmq::send_flags::none);
    std::cout << "  SENT:\n-----\n" << result_string << "\n-----" << std::endl;

    return 0;
}

publisher::publisher(const char* addr)
{
    // initialize the zmq context with a single IO thread
    this->context = zmq::context_t{1};
    std::cout << "pub context created" << std::endl;

    // construct a REP (reply) socket and bind to interface
    this->socket = zmq::socket_t{context, zmq::socket_type::pub};
    std::cout << "pub socket created" << std::endl;
    this->socket.bind(addr);
    std::cout << "pub obj created" << std::endl;
}

publisher::~publisher()
{
    this->socket.close();
}
/*
int main()
{
    publisher pub;
    std::cout << "pub created" << std::endl;
    pub.worker("data");
    std::cout << "pub works" << std::endl;
}
*/