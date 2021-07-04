#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <thread>

#include <zmq.hpp>

#include "subscriber/subscriber.hpp"
#include "publisher/publisher.hpp"

void pub_thread()
{
    publisher pub;
    std::cout << "pub created" << std::endl;
    pub.worker("publisher/data");
    std::cout << "pub works" << std::endl;
}

void sub_thread()
{
    subscriber sub;
    std::cout << "sub created" << std::endl;
    sub.worker();
    std::cout << "sub works" << std::endl;
}

int main() 
{
    /*
    std::cout << "started" << std::endl;
    publisher pub("tcp://*:5678");
    std::cout << "pub created" << std::endl;
    subscriber sub("tcp://localhost:5678");
    std::cout << "sub created" << std::endl;

    sub.worker();
    std::cout << "sub works" << std::endl;

    pub.worker();
    std::cout << "pub works" << std::endl;
    */
    
    std::thread pub_trd(pub_thread);
    std::thread sub_trd(sub_thread);

    pub_trd.join();
    sub_trd.join();
    
    return 0;
}
