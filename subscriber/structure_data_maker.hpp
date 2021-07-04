#pragma once

#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>

std::vector<std::string> split(const std::string s, const std::string delimiter);

using data_line = std::tuple<std::string, std::string, std::string, std::string, std::string>;

class student_data : public std::vector<data_line>
{
public:
    std::string data_to_string();
    void range_data();
};

student_data string_to_data(const std::string string);
