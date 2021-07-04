#pragma once

#include <string>
#include <vector>
#include <tuple>

#include <iostream>

namespace data_joiner
{
    using data_line = std::tuple<std::string, std::string, std::string>;

    class student_data : public std::vector<data_line>
    {
    public:
        student_data intersection(const student_data right);
        std::string data_to_string();
    };

    student_data intersection(const student_data left, const student_data right);
}
