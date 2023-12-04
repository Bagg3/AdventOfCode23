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
    int cardNum;
};

// Function to process a single line and return the struct
CardData processCardData(const string line)
{
    CardData cardData;

    istringstream iss(line);
    string leftPart, rightPart, cardVal;
    getline(iss, cardVal, ':');
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

    // Extract the card number from the cardVal string
    istringstream issCard(cardVal);
    string discardCard;
    string cardNumStr;
    getline(issCard, discardCard, ' '); // Discard the word "Card"
    getline(issCard, cardNumStr);

    cardData.cardNum = stoi(cardNumStr);

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
    // vector<string> lines = readLinesFromFile("input.txt");

    vector<string> lines = {"Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53",
                            "Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19",
                            "Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1",
                            "Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83",
                            "Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36",
                            "Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11"};

    int sum = 0;

    vector<int> numOfCards;

    // NEEDS TO COUNT AMOUNT UP
    for (auto line : lines)
    {
        int matches = 0;
        CardData cardData = processCardData(line);

        cout << "Card " << cardData.cardNum << endl;

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
        matches = 0;
    }

    for (int i = 0; i < numOfCards.size(); i++)
    {
        sum += numOfCards[i];
    }

    cout << "Sum: " << sum << endl;
    return 0;
}
