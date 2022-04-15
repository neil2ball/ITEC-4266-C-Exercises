// Ball - Assignment 5 - 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int findAmount(string ask);
double findDoubleAmount(string ask);

int main()
{
    struct computerType
    {
        string manufacturer;
        string modelType;
        string processorType;
        int ram;
        int hardDriveSize;
        int year;
        double price;

    };

    computerType yourComputer;

    cout << "What is your computer manufacturer? " << flush;
    cin >> yourComputer.manufacturer;

    cout << "What is your computer model? " << flush;
    cin >> yourComputer.modelType;

    cout << "What is your computer processor type? " << flush;
    cin >> yourComputer.processorType;

    yourComputer.ram = findAmount("How many GB of RAM do you have? ");
    yourComputer.hardDriveSize = findAmount("How many GB of hard drive space do you have? ");
    yourComputer.year = findAmount("What year was your computer manufactured? ");
    yourComputer.price = findDoubleAmount("How much did you pay for your computer? ");

    cout << "Your computer manufacturer is: " << yourComputer.manufacturer << endl;
    cout << "Your computer model type is: " << yourComputer.modelType << endl;
    cout << "Your computer processor type is: " << yourComputer.processorType << endl;
    cout << "Your computer RAM amount in GB is: " << yourComputer.ram << endl;
    cout << "Your computer hard drive type is: " << yourComputer.hardDriveSize << endl;
    cout << "Your computer manufacturer year is: " << yourComputer.year << endl;
    cout << "Your computer price is: " << yourComputer.price << endl;
}

int findAmount(string ask)
{
    int output = 0;

    //https://stackoverflow.com/questions/784563/c-check-whether-is-number-is-int-float

    cout << ask << flush;
    cin >> output;
    cout << endl;

    //https://wiki.cs.byu.edu/cs-142/checking-cin-fail

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

double findDoubleAmount(string ask)
{
    double output = 0;

    //https://stackoverflow.com/questions/784563/c-check-whether-is-number-is-int-float

    cout << ask << flush;
    cin >> output;
    cout << endl;

    //https://wiki.cs.byu.edu/cs-142/checking-cin-fail

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
