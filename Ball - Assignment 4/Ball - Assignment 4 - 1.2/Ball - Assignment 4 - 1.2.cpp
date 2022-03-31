// Ball - Assignment 4 - 1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int commaCount = 0;
    int commaFirst = 0;
    int commaSecond = 0;
    int commaThird = 0;
    string str;
    cout << "Enter your name, Social Security number, user ID, and password (delimited by commas where user ID and password do not contain spaces): ";
    getline(cin, str);


    if (commaCount == 0)
    {
        commaFirst = str.find(",");
        commaCount++;
    }
    if (commaCount == 1)
    {
        commaSecond = str.find(",", commaFirst + 1);
        commaCount++;
    }
    if (commaCount == 2)
    {
        commaThird = str.find(",", commaSecond + 1);
        commaCount++;
    }

    for (int x = commaFirst + 1; x < commaSecond; x++)
    {
        if (str.at(x) == ' ' || str.at(x) == '-')
            continue;
        str.replace(x, 1, "x");
    }

    for (int x = commaThird + 1; x < str.length(); x++)
    {
        str.replace(x, 1, "x");
    }

    cout << str;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
