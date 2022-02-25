// Ball - Assignment 2 - 2.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

int findAmount(string ask);
float findFloatAmount(string ask);

int main()
{
    string sexStr = "Select 1 for Female and 0 for Male: ";
    int sex = findAmount(sexStr);

    string bodyWeightStr = "Body weight: ";
    string wristMeasureStr = "Wrist measurement: ";
    string waistMeasureStr = "Waist measurement: ";
    string hipMeasureStr = "Hip measurement: ";
    string forearmMeasureStr = "Forearm measurement: ";

    float bodyWeight = 0;
    float wristMeasurement = 0;
    float waistMeasurement = 0;
    float hipMeasurement = 0;
    float forearmMeasurement = 0;
    float bodyFat = 0;
    float bodyFatPercentage = 0;
    float a1 = 0;
    float a2 = 0;
    float a3 = 0;
    float a4 = 0;
    float a5 = 0;
    float b = 0;

    cout << fixed;

    switch (sex)
    {
        case 0:
            bodyWeight = findFloatAmount(bodyWeightStr);
            waistMeasurement = findFloatAmount(waistMeasureStr);
            a1 = (bodyWeight * 1.082) + 94.42;
            a2 = waistMeasurement * 4.15;
            b = a1 - a2;
            bodyFat = bodyWeight - b;
            bodyFatPercentage = bodyFat * 100 / bodyWeight;
            cout << "Body fat: " << bodyFat << endl;
            cout << "Body fat percentage: " << bodyFatPercentage << endl;
            break;
            

        case 1:
            bodyWeight = findFloatAmount(bodyWeightStr);
            wristMeasurement = findFloatAmount(wristMeasureStr);
            waistMeasurement = findFloatAmount(waistMeasureStr);
            hipMeasurement = findFloatAmount(hipMeasureStr);
            forearmMeasurement = findFloatAmount(forearmMeasureStr);

            a1 = (bodyWeight * 0.732) + 8.987;
            a2 = wristMeasurement / 3.140;
            a3 = waistMeasurement * 0.157;
            a4 = hipMeasurement * 0.249;
            a5 = forearmMeasurement * 0.434;
            b = a1 + a2 - a3 - a4 + a5;
            bodyFat = bodyWeight - b;
            bodyFatPercentage = bodyFat * 100 / bodyWeight;
            cout << "Body fat: " << bodyFat << endl;
            cout << "Body fat percentage: " << bodyFatPercentage << endl;
            break;

        default:
            break;

    }

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

float findFloatAmount(string ask)
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
