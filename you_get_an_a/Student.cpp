#include "Student.h"

Student::Student(string first_name, string last_name, string student_id) {
	this->first_name = first_name;
	this->last_name = last_name;
	this->student_id = student_id;
}

string Student::get_first_name() {
	return first_name;
}

string Student::get_last_name() {
	return last_name;
}

string Student::get_student_id() {
	return student_id;
}

void Student::create_assignment(string assignment_name) {
	Assignment place_holder(assignment_name, 0);
	student_assignment.push_back(place_holder);
}

void Student::grade_assignment(string assignment_name, int points) {
	for (int i = 0; i != student_assignment.size(); i++) {
		if (student_assignment[i].get_assignment_name() == assignment_name) {
			student_assignment[i].set_points(points);
		}
	}
}

int Student::get_grade(string assignment_name) {
	for (int i = 0; i != student_assignment.size(); i++) {
		if (student_assignment[i].get_assignment_name() == assignment_name) {
			return student_assignment[i].get_points();
		}
	}
}