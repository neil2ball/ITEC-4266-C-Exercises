// Ball - Assignment 4 - 2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int averageHigh(int data[]);
int averageLow(int data[]);
int indexHighTemp(int data[]);
int indexLowTemp(int data[]);
int getData(int month, int lowHigh);

int main()
{
    int data[12][2];

    for (int x = 0; x < 12; x++)
    {
        for (int y = 0; y < 2; y++)
            data[x][y] = getData(x, y);
    }

    int dataIn[12];

    for (int x = 0; x < 12; x++)
        dataIn[x] = data[x][1];

    cout << "Average High: " << averageHigh(dataIn) << endl;
    cout << "Index of Highest High: " << "data[" << indexHighTemp(dataIn) << "][1]" << endl;

    for (int x = 0; x < 12; x++)
        dataIn[x] = data[x][0];

    cout << "Average Low: " << averageLow(dataIn) << endl;
    cout << "Index of Lowest Low: " << "data[" <<indexLowTemp(dataIn) << "][0]" << endl;


}

int averageHigh(int data[])
{
    int sum = 0;

    for (int x = 0; x < 12; x++)
        sum += data[x];

    return sum / 12;
}

int averageLow(int data[])
{
    int sum = 0;

    for (int x = 0; x < 12; x++)
        sum += data[x];

    return sum / 12;
}

int indexHighTemp(int data[])
{
    int high = 0;

    for (int x = 0; x < 12; x++)
    {
        if (data[x] > data[high])
            high = x;
    }

    return high;
}

int indexLowTemp(int data[])
{
    int low = 0;

    for (int x = 0; x < 12; x++)
    {
        if (data[x] < data[low])
            low = x;
    }

    return low;
}

int getData(int month, int lowHigh)
{
    string monthStr;
    string lowHighStr;
    switch (month)
    {
    case 0:
        monthStr = "January: ";
        break;
    case 1:
        monthStr = "February: ";
        break;
    case 2:
        monthStr = "March: ";
        break;
    case 3:
        monthStr = "April: ";
        break;
    case 4:
        monthStr = "May: ";
        break;
    case 5:
        monthStr = "June: ";
        break;
    case 6:
        monthStr = "July: ";
        break;
    case 7:
        monthStr = "August: ";
        break;
    case 8:
        monthStr = "September: ";
        break;
    case 9:
        monthStr = "October: ";
        break;
    case 10:
        monthStr = "November: ";
        break;
    case 11:
        monthStr = "December: ";
        break;
    }

    switch (lowHigh)
    {
    case 0:
        lowHighStr = "Low";
        break;
    case 1:
        lowHighStr = "High";
        break;
    }

    int output = 0;

    //https://stackoverflow.com/questions/784563/c-check-whether-is-number-is-int-float

    cout << "Please enter the "<< lowHighStr << " for the month of " << monthStr << flush;
    cin >> output;
    cout << endl;

    //https://wiki.cs.byu.edu/cs-142/checking-cin-fail

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter the " << lowHighStr << " for the month of " << monthStr << flush;
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
