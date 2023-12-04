#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> readLinesFromFile(const std::string &filename)
{
    std::ifstream input(filename);

    if (!input.is_open())
    {
        std::cerr << "Could not open file: " << filename << std::endl;
        return {}; // Return an empty vector if the file cannot be opened
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(input, line))
    {
        lines.push_back(line);
    }

    input.close();

    return lines;
}

int main()
{
    std::vector<std::string> lines = readLinesFromFile("input.txt");

    int sum = 0;

    return 0;
}
