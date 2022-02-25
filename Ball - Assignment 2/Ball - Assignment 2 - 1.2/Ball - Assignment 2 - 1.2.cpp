// Ball - Assignment 2 - 1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

float findAmount(string ask);

int main()
{
    string netBalStr = "Enter the balance on the bill: ";
    string d1Str = "Enter the number of days in the billing cycle: ";
    string d2Str = "Enter the number of days before the billing cycle that payment is made: ";
    string paymentStr = "Enter the payment: ";
    string interestRateStr = "Enter your interest rate: ";

    float netBalance = findAmount(netBalStr);
    float d1 = findAmount(d1Str);
    float d2 = findAmount(d2Str);
    float payment = findAmount(paymentStr);
    float interestRate = findAmount(interestRateStr);

    cout << setprecision(2) << fixed;

    cout << "The interest is " << (((netBalance * d1 - payment * d2) / d1) * interestRate) << "." << endl;
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
