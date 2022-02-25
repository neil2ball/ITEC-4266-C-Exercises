// Ball - Assignment 2 - 2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double findAmount(string ask);

int main()
{
    string aStr = "Enter the coefficient of x^2 (a): ";
    string bStr = "Enter the coefficient of x (b): ";
    string cStr = "Enter the constant (c): ";

    double a = findAmount(aStr);
    double b = findAmount(bStr);
    double c = findAmount(cStr);

    float d = pow(b, 2) - 4.0 * a * c;

    cout << fixed;

    if (d >= 0)
    {
        cout << "The equation has two real roots." << endl;
        cout << (-b + pow(d, 0.5)) / (2.0 * a) << endl;
        cout << (-b - pow(d, 0.5)) / (2.0 * a) << endl;
    }
    else
    {
        cout << "The equation has two complex roots." << endl;
    }
}

double findAmount(string ask)
{
    double output = 0;

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
