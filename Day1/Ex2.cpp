#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

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

int doesSubstringExists(std::string s1, std::string s2)
{
    // calculating the length of the main string and the substring
    int len1 = s1.length();
    int len2 = s2.length();

    // loop to iterate at each character in the string s1 to match the string s2
    for (int i = 0; i <= len1 - len2; i++)
    {
        int j;

        // inner loop to iterate over each character in the string s2, if it matches that particular string s1 char group, on which we are currently iterating from the outer loop
        for (j = 0; j < len2; j++)
        {
            if (s1[i + j] != s2[j])
            {
                // breaking the loop if the match fails
                break;
            }
        }
        if (j == len2)
        {
            // returning the current index of i, if finally match completed
            return i;
        }
    }
    // else returning -1
    return -1;
}

int main()
{
    std::vector<std::string> lines = readLinesFromFile("input.txt");

    int sum = 0;
    std::string numAsString[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // Loop through all lines
    for (auto line : lines)
    {
        // Map of the index of the number and the number
        std::map<int, int> numbers;

        for (int i = 0; i < 10; i++)
        {
            int index = doesSubstringExists(line, numAsString[i]);
            if (index != -1)
            {
                numbers.insert(std::pair<int, int>(index, i));
            }
        }

        for (size_t i = 0; i < line.size(); i++)
        {
            // Check if char is a number and if it is insert in the map
            if (line[i] >= '0' && line[i] <= '9')
            {
                numbers.insert(std::pair<int, int>(i, line[i] - '0'));
            }
        }

        // Find the smallest and the biggest index in the map
        int smallestIndex = numbers.begin()->first;
        int biggestIndex = numbers.begin()->first;

        for (auto it = numbers.begin(); it != numbers.end(); ++it)
        {
            if (it->first < smallestIndex)
            {
                smallestIndex = it->first;
            }
            if (it->first > biggestIndex)
            {
                biggestIndex = it->first;
            }
        }

        // Get the number from the map with the smallest index and convert it to string
        std::string numComb = std::to_string(numbers[smallestIndex]);

        // Get the number from the map with the biggest index and convert it to string
        numComb += std::to_string(numbers[biggestIndex]);
        // Convert string to int and add to sum
        sum += std::stoi(numComb);

        std::cout << sum << std::endl;
    }

    std::cout << "Sum: " << sum << std::endl;
}