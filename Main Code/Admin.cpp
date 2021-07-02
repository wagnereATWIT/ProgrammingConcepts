//Admin.cpp
#include "User.h"
#include "Admin.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int main(){}
//CONSTRUCTOR
Admin::Admin(string fName, string lName, int ID, string office)
	:User{ fName, lName, ID }
{
	this->adOffice = office;
}

//FUNCTIONS
string Admin::toString() const
{
	ostringstream output;
	output << "User Credentials" << endl
		<< "First name: " << getFirstName() << endl
		<< "Last Name: " << getLastName() << endl
		<< "ID Number: " << getID() << endl
		<< "Office: " << getOffice() << endl;
	return output.str();
}

void Admin::setOffice(string office)
{
	adOffice = office;
}

string Admin::getOffice() const
{
	return adOffice;
}

void Admin::addRemoveCourse()
{
	cout << "Add/Remove course function called" << endl;
}

void Admin::addRemoveUser()
{
	cout << "Add/Remove user function called" << endl;
}

void Admin::addRemoveStudCourse()
{
	cout << "Add/Remove student from course function called" << endl;
}

void Admin::searchCourse()
{
	cout << "Search course function called" << endl;
}

void Admin::searchRoster()
{
	cout << "Search class list function called" << endl;
}

void Admin::printRoster() const
{
	cout << "Print class list function called" << endl;
}

void Admin::printCourse() const
{
	cout << "Print course function called" << endl;
}

//DESTRUCTOR
Admin::~Admin()
{
	cout << "Destructor for Admin called" << endl;
}
