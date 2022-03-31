// Ball - Assignment 4 - 1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char v);
string removeVowel(string strIn);

int main()
{
    //https://www.learncpp.com/cpp-tutorial/input-with-istream/
    cout << "Enter your string: ";
    string str;
    getline(cin, str);

    cout << removeVowel(str);

}

bool isVowel(char v)
{

    if (v == 'a' || v == 'A'
        || v == 'e' || v == 'E'
        || v == 'i' || v == 'I'
        || v == 'o' || v == 'O'
        || v == 'u' || v == 'U')
        return true;

    return false;
}

string removeVowel(string strIn)
{
    string strOut;

    for (int x = 0; x < strIn.length(); x++)
    {
        if (isVowel(strIn[x]))
            continue;

        strOut += strIn[x];
    }

    return strOut;
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
