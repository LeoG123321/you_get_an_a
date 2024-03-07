#pragma once
#include "Student.h"
using namespace std;
class Gradebook
{
private:
	vector<Student> student_list;
	vector<Assignment> class_assignment;	//The new assignemnt that the students will be graded on
public:
	Gradebook();
	void add_student(string, string, string);	//Creates a new student and adds them into the list
	void add_assignment(string, int);			//creates a new assignment and add them into the list and adds them into the students as well
	void grade_assignment(string, string, string, int);	//grades the assignments of students by finding the student with their name and finding the assignment by the name of the assignment
	void grade_assignment(string, string, int);	//grades the assignments of students by finding the student with their id and finding the assignment by the name of the assignment
	vector<string> report();
};

