//Instructor.cpp
#include "User.h"
#include "Instructor.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//CONSTRUCTOR
Instructor::Instructor(string fName, string lName, int ID, string school)
	:User{ fName, lName, ID }
{
	this->schoolType = school;
}

//FUNCTIONS
string Instructor::toString() const
{
	ostringstream output;
	output << "User Credentials" << endl
		<< "First name: " << getFirstName() << endl
		<< "Last Name: " << getLastName() << endl
		<< "ID Number: " << getID() << endl
		<< "School: " << getSchool() << endl;
	return output.str();
}

void Instructor::setSchool(string school)
{
	schoolType = school;
}

string Instructor::getSchool() const
{
	return schoolType;
}

void Instructor::searchCourse()
{
	cout << "Search course function called" << endl;
}

void Instructor::printRoster() const
{
	cout << "Print class list function called" << endl;
}

void Instructor::printSchedule() const
{
	cout << "Print schedule function called" << endl;
}

//DESTRUCTOR
Instructor::~Instructor()
{
	cout << "Destructor for Instructor called" << endl;
}
