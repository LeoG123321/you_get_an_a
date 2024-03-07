#pragma once
#include <string>
using namespace std;
class Assignment
{
private:
	string assignment_name;
	int points;
public:
	Assignment(string, int);	//Creates the assingment and how many points

	string get_assignment_name();	
	int get_points();				
	void set_points(int);
};

