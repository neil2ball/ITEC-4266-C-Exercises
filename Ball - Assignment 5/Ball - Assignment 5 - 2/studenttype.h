#pragma once
#include <iostream>

using namespace std;

class studenttype
{

    string firstName;
    string lastName;
    char courseGrade;
    int testScore;
    int programmingScore;
    double gpa;



public:
    void getFirstName() { cin >> firstName; }

    void getLastName() { cin >> lastName; }

    //courseGrade depends on gpa
    void getCourseGrade() {if (gpa == 4.0) { courseGrade = 'A'; } else if (gpa == 3.0) { courseGrade = 'B'; } else if (gpa == 2.0) { courseGrade = 'C'; } else if (gpa == 1.0) { courseGrade = 'D'; } else if (gpa == 0.0) { courseGrade = 'F'; }}

    void getTestScore(){ testScore = findAmount("What is the student's assessment average? "); }

    void getProgrammingScore(){ programmingScore = findAmount("What is the student's classwork average? "); }

    //getGpa must be executed before getCourseGrade
    void getGpa(){ double gradeScore = testScore * 0.7 + programmingScore * 0.3; if (gradeScore >= 90) { gpa = 4.0; } else if (gradeScore >= 80) { gpa = 3.0; } else if (gradeScore >= 70) { gpa = 2.0; }else if (gradeScore >= 60) { gpa = 1.0; } else { gpa = 0.0; }}
    
    string name(){ return firstName + " " + lastName; }

    char letterGrade(){ return courseGrade; }

    double gpaOut(){ return gpa; }

    int findAmount(string ask) { int output = 0; cout << ask << flush; cin >> output; cout << endl; while (cin.fail())  { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); cout << ask << flush; cin >> output; cout << endl; } return output; }

    studenttype() {};
};