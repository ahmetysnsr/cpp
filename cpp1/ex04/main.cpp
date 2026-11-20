#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage: ./replace filename nonempty_search replacement" << std::endl;
        return 1;
    }
    std::string search = argv[2];
    std::string replacement = argv[3];
    if (search.empty())
    {
        std::cout << "Search text cannot be empty." << std::endl;
        return 1;
    }
    std::ifstream input(argv[1], std::ios::binary);
    if (!input)
    {
        std::cout << "Cannot open input file." << std::endl;
        return 1;
    }
    std::string content;
    char byte;
    while (input.get(byte))
        content += byte;
    if (!input.eof())
    {
        std::cout << "Cannot read input file." << std::endl;
        return 1;
    }
    input.close();
    std::string outputName = std::string(argv[1]) + ".replace";
    std::ofstream output(outputName.c_str(), std::ios::binary);
    if (!output)
    {
        std::cout << "Cannot open output file." << std::endl;
        return 1;
    }
    std::string::size_type start = 0;
    std::string::size_type found = content.find(search, start);
    while (found != std::string::npos)
    {
        output << content.substr(start, found - start) << replacement;
        start = found + search.size();
        found = content.find(search, start);
    }
    output << content.substr(start);
    output.close();
    if (!output)
    {
        std::cout << "Cannot write output file." << std::endl;
        return 1;
    }
    return 0;
}
