// Ball - Assignment 1 - 1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//https://www.tutorialspoint.com/cplusplus/cpp_functions.htm
//Function declaration
int findAmount(string ask);

int main()
{
    /*Lots in the US are normally given in acres or square feet.
      5000 square yards is converted to square feet.
    */
    float mowingPrice = 35.0f / 15000.0f;
    int fertPrice = 30;
    int treePrice = 50;

    string areaAsk = "Please enter the area of your lawn that you would like mowed to the nearest square foot: ";
    string fertAsk = "Please enter the number of fertilizer applications you would like: ";
    string treeAsk = "Please enter the number of trees you would like planted: ";

    int area = findAmount(areaAsk);
    int fert = findAmount(fertAsk);
    int tree = findAmount(treeAsk);

    float mowCost = area * mowingPrice;

    /*This allows for rounding to the nearest cent.
      It was inspired by but not taken from:
      https://stackoverflow.com/questions/11208971/round-a-float-to-a-regular-grid-of-predefined-points
    */
    mowCost = mowCost * 100;
    mowCost = round(mowCost);
    mowCost = mowCost / 100;

    int fertCost = fert * fertPrice;
    int treeCost = tree * treePrice;

    float total = mowCost + fertCost + treeCost;

    //https://stackoverflow.com/questions/14432043/float-formatting-in-c

    printf("Mowing cost:        $%.2f\n", mowCost);
    cout << "Fertlizer cost:     $" << fertCost << endl;
    cout << "Tree planting cost: $" << treeCost << endl;
    cout << endl;
    printf("Total cost:         $%.2f\n", total);

    cout << "\nPress any key to exit." << endl;

    //https://stackoverflow.com/questions/7010760/c-keypress-getch-cin-get

    cin.get();
    cin.ignore();
    
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
