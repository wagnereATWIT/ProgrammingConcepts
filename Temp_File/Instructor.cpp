//Instructor.cpp
#include "Instructor.h"
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

void Instructor::printRoster() const
{
	cout << "Print class list function called" << endl;
}

void Instructor::printSchedule() const
{
	cout << "Print schedule function called" << endl;
}

//SET & GET FUNCTIONS
void Instructor::setSchool(string school) { schoolType = school; }
string Instructor::getSchool() const { return schoolType; }

//DESTRUCTOR
Instructor::~Instructor()
{
	cout << "Destructor for Instructor called" << endl;
}