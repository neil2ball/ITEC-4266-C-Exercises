// Ball - Assignment 6 - 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

int findAmount(string ask);

int main()
{

    string* candidate;
    int* votes;
    int arraySize = findAmount("How many candidates are there? ");
    int total = 0;
    int winnerIndex = 0;


    candidate = new string[arraySize];
    votes = new int[arraySize];

    for (int a = 0; a < arraySize; a++)
    {
        cout << "Enter the name of candidate number " << a + 1 << ": ";
        cin >> candidate[a];
        cout << "Enter the number of votes received by " << candidate[a] << ": ";
        cin >> votes[a];
        total += votes[a];
    }

    //https://stackoverflow.com/questions/15674097/output-aligned-columns
    cout << left << setw(20) << "\n\nCandidate" << left << setw(20) << "Votes Received" << "% of Total Votes\n" << endl;

    for (int a = 0; a < arraySize; a++)
    {
        //https://stackoverflow.com/questions/5907031/printing-the-correct-number-of-decimal-points-with-cout
        cout << std::fixed;
        cout << setprecision(2);
        cout << left << setw(24) << candidate[a] << left << setw(19) << votes[a] << (float)((float)votes[a] / (float)total) * 100.0 << endl;

        if (votes[a] > votes[winnerIndex])
            winnerIndex = a;
    }

    cout << left << setw(24) << "Total" << total;

    cout << "\n\nThe Winner of the Election is ";
    cout << candidate[winnerIndex] << ".";
}

int findAmount(string ask)
{
    int output = 0;

    //https://stackoverflow.com/questions/784563/c-check-whether-is-number-is-int-float

    cout << ask << flush;
    cin >> output;
    cout << endl;

    /*https://wiki.cs.byu.edu/cs-142/checking-cin-fail    */
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
