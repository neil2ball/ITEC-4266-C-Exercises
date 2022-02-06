// Ball - Assignment 1 - 2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//https://www.tutorialspoint.com/cplusplus/cpp_functions.htm
//Function declaration
int findAmount(string ask);

int main()
{

    string nickelAsk = "How many nickels do you have? ";
    string dimeAsk = "How many dimes do you have? ";
    string quarterAsk = "How many quarters do you have? ";

    int nickelCount = findAmount(nickelAsk);
    int dimeCount = findAmount(dimeAsk);
    int quarterCount = findAmount(quarterAsk);

    cout << "Total in pennies: " << 25 * quarterCount + 5 * nickelCount + 10 * dimeCount << flush;

    //https://www.daniweb.com/programming/software-development/threads/347801/cent-symbol-in-c

    cout << char(155) << endl;

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