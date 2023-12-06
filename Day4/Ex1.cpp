#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

// Define a struct to hold the left and right vectors
struct CardData
{
    vector<int> leftNums;
    vector<int> rightNums;
};

// Function to process a single line and return the struct
CardData processCardData(const string line)
{
    CardData cardData;

    istringstream iss(line);
    string leftPart, rightPart, junk;
    getline(iss, junk, ':');
    getline(iss, leftPart, '|');
    getline(iss, rightPart);

    istringstream issLeft(leftPart);
    int num;
    while (issLeft >> num)
    {
        cardData.leftNums.push_back(num);
    }

    istringstream issRight(rightPart);
    while (issRight >> num)
    {
        cardData.rightNums.push_back(num);
    }

    return cardData;
}

vector<string> readLinesFromFile(const string &filename)
{
    ifstream input(filename);

    if (!input.is_open())
    {
        cerr << "Could not open file: " << filename << endl;
        return {}; // Return an empty vector if the file cannot be opened
    }

    vector<string> lines;
    string line;

    while (getline(input, line))
    {
        lines.push_back(line);
    }

    input.close();

    return lines;
}

int main()
{
    vector<string> lines = readLinesFromFile("input.txt");

    /*
        vector<string> test = {"Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53",
                               "Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19",
                               "Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1",
                               "Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83",
                               "Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36",
                               "Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11"};
    */
    int sum = 0;

    for (auto line : lines)
    {
        int matches = 0;
        int tempSum = 0;
        CardData cardData = processCardData(line);

        // Loop through all left numbers and check if they are in the right numbers
        for (auto leftNum : cardData.leftNums)
        {
            for (auto rightNum : cardData.rightNums)
            {
                if (leftNum == rightNum)
                {
                    matches++;
                }
            }
        }
        cout << "Matches: " << matches << endl;
        tempSum += pow(2, matches - 1);
        matches = 0;
        sum += tempSum;
        tempSum = 0;
    }

    cout << "Sum: " << sum << endl;
    return 0;
}
