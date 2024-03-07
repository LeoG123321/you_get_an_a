#include "Assignment.h"

Assignment::Assignment(string assignment_name, int points) {
	this->assignment_name = assignment_name;
	this->points = points;
}

string Assignment::get_assignment_name() {
	return assignment_name;
}

int Assignment::get_points() {
	return points;
}

void Assignment::set_points(int points) {
	this->points = points;
}