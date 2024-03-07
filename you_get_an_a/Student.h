#pragma once
#include "Assignment.h"
#include <vector>
using namespace std;

class Student
{
private:
	string first_name;
	string last_name;
	string student_id;
	vector<Assignment> student_assignment;	//The assignment of the students and how they did on them
public:
	Student(string, string, string);	//Creates students with a first and last name and id 
	string get_first_name();
	string get_last_name();
	string get_student_id();
	void create_assignment(string);		//creates the assingment the students need to complete, and gives them a 0 for incomplete
	void grade_assignment(string, int);	//grades the assingment by first finding the name of the assingment and inputting their grade
	int get_grade(string); //finds the grade of the assignemnt that the student got
};

