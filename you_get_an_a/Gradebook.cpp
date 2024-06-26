#include "Gradebook.h"


Gradebook::Gradebook() {
	return;
}

void Gradebook::add_student(string first_name, string last_name, string student_id) {
	Student place_holder(first_name, last_name, student_id);
	student_list.push_back(place_holder);
	//When adding a new student, include all the assignments form the class into them
	for (int i = 0; i < class_assignment.size(); i++) {
		student_list[i].create_assignment(class_assignment[i].get_assignment_name());
	}
}

void Gradebook::add_assignment(string assignment_name, int points) {
	Assignment place_holder(assignment_name, points);
	class_assignment.push_back(place_holder);
	for (int i = 0; i < student_list.size(); i++) {
		student_list[i].create_assignment(assignment_name);
	}
}

void Gradebook::grade_assignment(string first_name, string last_name, string assignment_name, int points) {
	for (int i = 0; i < student_list.size(); i++) {
		if (student_list[i].get_first_name() == first_name && student_list[i].get_last_name() == last_name) {
			student_list[i].grade_assignment(assignment_name, points);
		}
	}
}

void Gradebook::grade_assignment(string student_id, string assignment_name, int points) {
	for (int i = 0; i < student_list.size(); i++) {
		if (student_list[i].get_student_id() == student_id) {
			student_list[i].grade_assignment(assignment_name, points);
		}
	}
}

vector<string> Gradebook::report() {
	vector<string> temp;
	string place_holder = "";
	double total_points_earned = 0;
	double total_points_possible = 0;
	double average;
	for (int i = 0; i < student_list.size(); i++) {
		place_holder += student_list[i].get_first_name();
		place_holder += " ";
		place_holder += student_list[i].get_last_name();
		place_holder += ": ";
		place_holder += student_list[i].get_student_id();
		for (int j = 0; j < class_assignment.size(); j++) {
			place_holder += "\n\t";
			place_holder += class_assignment[j].get_assignment_name();
			place_holder += ": ";
			if (student_list[i].get_grade(class_assignment[j].get_assignment_name()) == -1) {
				place_holder += "N/A";
			}
			else {
				place_holder += to_string(student_list[i].get_grade(class_assignment[j].get_assignment_name()));
				total_points_earned += student_list[i].get_grade(class_assignment[j].get_assignment_name());
				total_points_possible += class_assignment[j].get_points();
			}
		}
		average = total_points_earned / total_points_possible;
		average *= 100;
		place_holder += "\nAverage Score: ";
		place_holder += to_string(average);
		temp.push_back(place_holder);
		place_holder = "";

		total_points_earned = 0;
		total_points_possible = 0;
	}
	return temp;
}

vector<string> Gradebook::assignment_report(string assignment_name) {
	vector<string> temp;
	string place_holder = "";
	double total_points_earned = 0;
	double total_assignments = 0;
	double average;

	int class_assignment_index = 0;

	for (int i = 0; i < class_assignment.size(); i++) {
		if (class_assignment[i].get_assignment_name() == assignment_name) {
			class_assignment_index = i;
		}
	}

	for (int i = 0; i < student_list.size(); i++) {
		place_holder += student_list[i].get_first_name();
		place_holder += " ";
		place_holder += student_list[i].get_last_name();
		place_holder += ": ";
		place_holder += student_list[i].get_student_id();
		
		place_holder += "\n\t";
		place_holder += "Score: ";
		if (student_list[i].get_grade(assignment_name) == -1) {
			place_holder += "N/A";
		}
		else {
			place_holder += to_string(student_list[i].get_grade(assignment_name));
			total_points_earned += student_list[i].get_grade(assignment_name);
			total_assignments++;
		}
		
		temp.push_back(place_holder);
		place_holder = "";
	}

	average = total_points_earned / total_assignments;

	place_holder += "\nAverage Score: ";
	place_holder += to_string(average);
	place_holder += " / ";
	place_holder += to_string(class_assignment[class_assignment_index].get_points());

	temp.push_back(place_holder);

	return temp;
}