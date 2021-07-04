#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "data_joiner.hpp"

namespace data_wrapper
{
    std::vector<std::string> split(const std::string s, const std::string delimiter);

    int data_wrapper(const std::string& path_to_file, data_joiner::student_data* data);
}
