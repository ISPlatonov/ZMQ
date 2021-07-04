#include "data_wrapper.hpp"

std::vector<std::string> data_wrapper::split(const std::string s, const std::string delimiter)
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

int data_wrapper::data_wrapper(const std::string& path_to_file, data_joiner::student_data* data)
{
    std::ifstream student_file;
    student_file.open(path_to_file);

    if (!student_file.is_open())
    {
        std::cerr << "File " << path_to_file << " is not open" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(student_file, line))
    {
        std::vector<std::string> data_line = split(line, " ");

        if (data_line.size() == 0)
            break;
        
        // deleting the index
        data_line.erase(data_line.begin());

        if (data_line.size() != 3)
        {
            std::cerr << "Invalid data in file" << std::endl;
            return 1;
        }
        data->emplace_back(data_line[0], data_line[1], data_line[2]);
    }
    student_file.close();

    return 0;
}
