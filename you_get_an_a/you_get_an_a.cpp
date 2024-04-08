/*
    Leonardo Gonzalez   3/6/2024

    Week 7              You Get an A!
*/

#include <iostream>
#include "Gradebook.h"
using namespace std;

int main()
{

    Gradebook gradebook;

    gradebook.add_student("Bob", "Bobberson", "ABC123");
    gradebook.add_student("Sam", "Sammerson", "DEF456");
    gradebook.add_student("Jess" ,"Jesserson", "HIJ789");

    gradebook.add_assignment("Quiz 1", 100);
    gradebook.add_assignment("Lab 1", 50);

    gradebook.grade_assignment("Sam", "Sammerson", "Quiz 1", 95);
    gradebook.grade_assignment("Bob", "Bobberson", "Quiz 1", 85);
    gradebook.grade_assignment("Jess", "Jesserson", "Lab 1", 49);
    gradebook.grade_assignment("HIJ789", "Quiz 1", 93);
    gradebook.grade_assignment("ABC123", "Lab 1", 0);


    cout << "Report: " << endl << endl;
    vector<string> report = gradebook.report();
    for (int i = 0; i < report.size(); i++) {
        cout << report[i] << "\n" << endl;
    }

    cout << "\n\nAssignment Report:" << endl << endl;
    vector<string> assignment_report = gradebook.assignment_report("Lab 1");
    for (int i = 0; i < assignment_report.size(); i++) {
        cout << assignment_report[i] << "\n" << endl;
    }

    cout << "\n\nAssignment Report:" << endl << endl;
    vector<string> assignment_report_2 = gradebook.assignment_report("Quiz 1");
    for (int i = 0; i < assignment_report_2.size(); i++) {
        cout << assignment_report_2[i] << "\n" << endl;
    }


    return 0;
}
