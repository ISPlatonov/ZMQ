#include "structure_data_maker.hpp"

std::string student_data::data_to_string()
{
    std::string result;
    for (auto data_line : *this)
    {
        result += (std::get<0>(data_line) + ' ' + std::get<1>(data_line) + ' ' + std::get<2>(data_line) + '\n');
    }
    return result;
}

std::vector<std::string> split(const std::string s, const std::string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string substr;
    std::vector<std::string> result;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        substr = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        result.push_back(substr);
    }

    result.push_back (s.substr (pos_start));
    return result;
}

student_data string_to_data(const std::string string)
{
    student_data result;
    std::vector<std::string> lines = split(string, "\n");
    for (auto line : lines)
    {
        auto split_line = split(line, " ");
        if (split_line.size() != 3)
            break;
        auto date = split(split_line[2], ".");
        std::vector<std::string> norm_date;
        for (auto num : date)
        {
            while (*num.begin() == '0')
                num.erase(num.begin());
            norm_date.push_back(num);
        }
        result.emplace_back(split_line[0], split_line[1], norm_date[0], norm_date[1], norm_date[2]);
    }
    return result;
}

void student_data::range_data()
{
    std::sort(this->begin(), this->end());
}
