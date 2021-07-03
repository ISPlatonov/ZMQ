#include "data_joiner.hpp"

//using namespace data_joiner;

data_joiner::student_data data_joiner::intersection(const data_joiner::student_data left, const data_joiner::student_data right)
{
    data_joiner::student_data result;
    for (auto left_line : left)
        for (auto right_line : right)
            if (left_line == right_line)
                result.push_back(left_line);
    return result;
}

data_joiner::student_data data_joiner::student_data::intersection(const student_data right)
{
    student_data result;
    for (auto left_line : *this)
        for (auto right_line : right)
            if (left_line == right_line)
                result.push_back(left_line);
    return result;
}

std::string data_joiner::student_data::data_to_string()
{
    std::string result;
    for (auto data_line : *this)
    {
        result += (std::get<0>(data_line) + ' ' + std::get<1>(data_line) + ' ' + std::get<2>(data_line) + '\n');
        std::cout << "str: %s" << (std::get<0>(data_line) + ' ' + std::get<1>(data_line) + ' ' + std::get<2>(data_line) + '\n');
    }
    return result;
}
