#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int main()
{
    std::ifstream input("input.txt");

    if (!input.is_open())
    {
        std::cout << "Could not open file" << std::endl;
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(input, line))
    {
        lines.push_back(line);
    }

    input.close();

    int sum = 0;

    for (auto line : lines)
    {
        std::string numComb;
        for (size_t i = 0; i < line.size(); i++)
        {
            char firstNum, secNum;
            bool firstNumFound = false;
            if (!firstNumFound)
            {
                if (line[i] >= '0' && line[i] <= '9')
                {
                    firstNum = line[i];
                    secNum = line[i];
                    firstNumFound = true;
                }
            }
            else if (line[i] < '0' || line[i] > '9')
            {
                char secNum = line[i];
            }

            if (i == line.size() - 1)
            {
                if (firstNum == secNum)
                {
                    numComb += firstNum;
                }
            }
        }
    }

    return 0;
}