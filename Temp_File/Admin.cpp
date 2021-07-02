//Admin.cpp

#include "Admin.h"
using namespace std;

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

void Admin::addRemoveCourse()								// *** NEED FOR ASSIGNMENT 5 ***
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

//SET & GET FUNCTIONS
void Admin::setOffice(string office) { adOffice = office; }
string Admin::getOffice() const { return adOffice; }

//DESTRUCTOR
Admin::~Admin()
{
	cout << "Destructor for Admin called" << endl;
}