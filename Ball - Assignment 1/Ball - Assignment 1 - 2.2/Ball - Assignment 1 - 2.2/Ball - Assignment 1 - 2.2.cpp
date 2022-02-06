// Ball - Assignment 1 - 2.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//https://www.tutorialspoint.com/cplusplus/cpp_functions.htm
//Function declaration
float findAmount(string ask);
float roundToCent(float startCost);

int main()
{ 
    float serviceCharge = 0.015f;

    float purchasePrice = findAmount("What is the purchase price? ");
    float salePrice = findAmount("What is the sale price? ");

    float numberShares = findAmount("What are the number of shares? ");


    float amountInvested        = purchasePrice * numberShares;
    float purchaseServiceCharge = amountInvested * serviceCharge;

    float saleSubtotal          = salePrice * numberShares;
    float saleServiceCharge     = saleSubtotal * serviceCharge;

    //Round to the nearest cent before presenting service charge.
    float totalServiceCharge    = purchaseServiceCharge + saleServiceCharge;

    float amountGainLoss        = roundToCent(saleSubtotal - amountInvested);

    float amountReceived = amountGainLoss - totalServiceCharge;

    printf("Amount invested:       $%.2f\n", amountInvested);
    printf("Total service charges: $%.2f\n", totalServiceCharge);
    printf("Amount Gained or Lost: $%.2f\n", amountGainLoss);
    printf("Amount Received:       $%.2f\n", amountReceived);

    cout << "\nPress any key to exit." << endl;

    //https://stackoverflow.com/questions/7010760/c-keypress-getch-cin-get

    cin.get();
    cin.ignore();
}

float findAmount(string ask)
{
    float output = 0.0f;

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

float roundToCent(float startCost)
{
  /*This allows for rounding to the nearest cent.
  It was inspired by but not taken from:
  https://stackoverflow.com/questions/11208971/round-a-float-to-a-regular-grid-of-predefined-points
  */
    startCost *= 100;
    startCost = round(startCost);
    startCost /= 100;

    return startCost;
}
