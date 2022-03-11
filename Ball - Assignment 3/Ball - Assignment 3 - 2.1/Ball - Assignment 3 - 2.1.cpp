// Ball - Assignment 3 - 2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int findAmount(string ask);
int reverseDigit(int digit);

int main()
{
    string digitAsk = "Enter an integer: ";

    cout << reverseDigit(findAmount(digitAsk)) << endl;

}

int reverseDigit(int digit)
{
    //https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
    string digitStr = to_string(digit);
    string buffer = digitStr;
    int count = 0;


    if (digit < 0)
    {
        
        buffer[count] = digitStr[0];
        count++;
        for (int i = digitStr.length() - 1; i > 0; i--)
        {
            buffer[count] = digitStr[i];
            count++;
        }
    }
    else if (digit == 0)
    {
        buffer[0] = digitStr[0];
    }
    else if (digit > 0)
    {
        for (int i = digitStr.length() - 1; i >= 0; i--)
        {
            buffer[count] = digitStr[i];
            count++;
        }
    }

    //https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int
    digit = stoi(buffer);

    return digit;
}

int findAmount(string ask)
{
    int output = 0;

    //https://stackoverflow.com/questions/784563/c-check-whether-is-number-is-int-float

    cout << ask << flush;
    cin >> output;
    cout << endl;

    /*https://wiki.cs.byu.edu/cs-142/checking-cin-fail
      "output < 1" satisfies the assumption that the user orders all three services.
    */
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << ask << flush;
        cin >> output;
        cout << endl;
    }

    return output;
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
