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

void data_wrapper::data_wrapper(const std::string& path_to_file, data_joiner::student_data* data)
{
    std::ifstream student_file;
    student_file.open(path_to_file);

    if (!student_file.is_open())
    {
        std::cerr << "File " << path_to_file << " is not open" << std::endl;
        return;
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
            return;
        }
        data->emplace_back(data_line[0], data_line[1], data_line[2]);
    }
    student_file.close();

    return;
}

/*
int main()
{
    data_joiner::student_data data_1, data_2, result_data;
    data_wrapper::data_wrapper("data/student_file_1.txt", &data_1);
    data_wrapper::data_wrapper("data/student_file_2.txt", &data_2);

    result_data = data_joiner::intersection(data_1, data_2);

    for (auto data_line : result_data)
    {
        std::cout << std::get<0>(data_line) << ' ' << std::get<1>(data_line) << ' ' << std::get<2>(data_line) << std::endl;
    }

    return 0;
}
*/
