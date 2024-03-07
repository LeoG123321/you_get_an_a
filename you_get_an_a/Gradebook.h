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
	void add_student(string, string, string);
	void add_assignment(string, int);
	void grade_assignment(string, string, string, int);
	string report();
};

