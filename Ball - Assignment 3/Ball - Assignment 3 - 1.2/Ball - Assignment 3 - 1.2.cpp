// Ball - Assignment 3 - 1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

float findAmount(string ask);

int main()
{
    string aPopStr = "Population A: ";
    string bPopStr = "Population B: ";

    float aPop = findAmount(aPopStr);
    float bPop = findAmount(bPopStr);

    string aGrowthStr = "Growth annual percentage rate of population A: ";
    string bGrowthStr = "Growth annual percentage rate of population B: ";

    float aGrowth = findAmount(aGrowthStr);
    float bGrowth = findAmount(bGrowthStr);

    while (aGrowth < bGrowth)
    {
        cout << "A growth must be greater than B growth." << endl;
        aGrowth = findAmount(aGrowthStr);
        bGrowth = findAmount(bGrowthStr);
    }

    aGrowth /= 100;
    bGrowth /= 100;

    int count = 0;

    while (aPop < bPop)
    {
        aPop = aPop * aGrowth + aPop;
        bPop = bPop * bGrowth + bPop;
        count++;
    }

    cout << "The years it will take for A to overtake B: " << count << endl;
}

float findAmount(string ask)
{
    float output = 0;

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
