//Student.cpp
#include "User.h"
#include "Student.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main(){}
//CONSTRUCTOR
Student::Student(string fName, string lName, int ID, double gpa)
	:User{ fName, lName, ID }
{
	this->studentGPA = gpa;
}

//FUNCTIONS
string Student::toString() const
{
	ostringstream output;
	output << "User Credentials" << endl
		<< "First name: " << getFirstName() << endl
		<< "Last Name: " << getLastName() << endl
		<< "ID Number: " << getID() << endl
		<< "GPA: " << getGPA() << endl;
	return output.str();
}

void Student::setGPA(double gpa)
{
	studentGPA = gpa;
}

double Student::getGPA() const
{
	return studentGPA;
}

void Student::searchCourse()
{ 
	cout << "Search course function called" << endl;
}

void Student::addDropCourse()
{
	cout << "Add/Drop course function called" << endl;
}

void Student::printSchedule() const
{
	cout << "Print schedule function called" << endl;
}

//DESTRUCTOR
Student::~Student()
{
	cout << "Destructor for Student called" << endl;
}
