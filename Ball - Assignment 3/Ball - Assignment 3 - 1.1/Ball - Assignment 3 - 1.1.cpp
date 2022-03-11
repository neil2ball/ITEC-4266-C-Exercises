// Ball - Assignment 3 - 1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int findAmount(string ask);

int main()
{
    string firstStr = "Please enter your first integer: ";
    string anotherStr = "Please enter your other integer: ";

    int first = findAmount(firstStr);
    int another = findAmount(anotherStr);

    int buffer = 0;
    int count = 0;
    int multThree = 0;
    int multFive = 0;

    if (first < another)
    {
        count = another - first;
        buffer = another;
    }
    else if (another < first)
    {
        count = first - another;
        buffer = first;
    }
    else
    {
        count = 1;
        buffer = first;
    }

    while (count >= 0)
    {
        if (buffer % 3 == 0)
        {
            multThree++;
        }
        if (buffer % 5 == 0)
        {
            multFive++;
        }
        buffer--;
        count--;
    }

    cout << "Multiples of 3: " << multThree << endl;
    cout << "Multiples of 5: " << multFive << endl;

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
