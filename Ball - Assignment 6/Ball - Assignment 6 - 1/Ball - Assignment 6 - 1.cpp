// Ball - Assignment 6 - 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <chrono>
#include <thread>
#include "extClockType.h"

int findAmount(string ask);

int main()
{
    cout << "What is the time zone?\n";
    cout << "[ 1 UTC-12:00, Y;   2 UTC-11:00, X;   3 UTC-10:00, W;   4 UTC-09:30, V†; 5 UTC-09:00, V;    6 UTC-08:00, U\n";
    cout << "  7 UTC-07:00, T;   8 UTC-06:00, S;   9 UTC-05:00, R;  10 UTC-04:00, Q; 11 UTC-03:30, P†;  12 UTC-03:00, P\n";
    cout << " 13 UTC-02:00, O;  14 UTC-01:00, N;  15 UTC±00:00, Z;  16 UTC+01:00, A; 17 UTC+02:00, B;   18 UTC+03:00, C\n";
    cout << " 19 UTC+03:30, C†; 20 UTC+04:00, D;  21 UTC+04:30, D†; 22 UTC+05 00, E; 23 UTC+05:30, E†;  24 UTC+05:45, E*\n";
    cout << " 25 UTC+06:00, F;  26 UTC+06:30, F†; 27 UTC+07:00, G;  28 UTC+08:00, H; 29 UTC+08:45, H*;  30 UTC+09:00, I\n";
    cout << " 31 UTC+09:30, I†; 32 UTC+10:00, K;  33 UTC+10:30, K†; 34 UTC+11:00, L; 35 UTC+12:00, M;   36 UTC+12:45, M*\n";
    cout << " 37 UTC+13:00, M†; 38 UTC+14:00, M†]\n";
    cout << "( https://en.wikipedia.org/wiki/List_of_UTC_offsets )\n";

    int timeZone = findAmount("Enter a number between 1 and 38 inclusive. ");

    int hr = findAmount("What is the hour? ");
    int min = findAmount("What is the minute? ");
    int sec = findAmount("What is the second? ");



    //http://www.cplusplus.com/forum/beginner/166003/
    extClockType *clock;
    clock = new extClockType(hr, min, sec, timeZone);

    while (true)
    {

        clock->incrementSeconds();
        clock->printTime();
        clock->printTimeZone();
        cout << "\r";

        //https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // sleep for 1 second
    }
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
