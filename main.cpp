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
    std::thread pub_trd(pub_thread);
    std::thread sub_trd(sub_thread);

    pub_trd.join();
    sub_trd.join();
    
    return 0;
}
