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

    // Loop through all lines
    for (auto line : lines)
    {
        std::string numComb;
        char firstNum = '\0';
        char lastNum = '\0';
        bool firstNumFound = false;

        // Loop through all chars in line
        for (size_t i = 0; i < line.size(); i++)
        {
            // Check if first number is found
            if (!firstNumFound)
            {
                // When first number is found, set firstNum and lastNum to that number
                if (line[i] >= '0' && line[i] <= '9')
                {
                    firstNum = line[i];
                    lastNum = line[i];
                    firstNumFound = true;
                }
            }

            // Check if last number is equal to the first number
            if (line[i] >= '0' && line[i] <= '9')
            {
                lastNum = line[i];
            }
        }
        // Convert chars to string and then to int
        numComb = firstNum;
        numComb += lastNum;
        sum += std::stoi(numComb);
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
