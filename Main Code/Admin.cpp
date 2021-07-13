//Admin.cpp
#include "Admin.h"
#include "Functions.h"
#include <string>
#include <stdio.h>
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

void Admin::addRemoveCourse(sqlite3* DB)
{
	char* messageError;
	char choice;
	string courseID, cID, cTitle, cDept, lecD, lecS, lecE, labD, labS, labE, cSem, cYear, cCredits;

	cout << "Would you like to add or drop a course?: " << endl
		<< "a - add" << endl
		<< "b - drop" << endl;
	cin >> choice;
	if (choice == 'a') {
		cout << endl << "Enter the following info for the class you would like to add: ";
		cout << endl << "CRN: "; cin >> cID;
		cout << endl << "Title: "; cin.ignore();  getline(cin, cTitle);
		cout << endl << "Department (four letter): "; cin >> cDept;
		cout << endl << "Lecture days (single letter): "; cin >> lecD;
		cout << endl << "Lecture start time: "; cin >> lecS;
		cout << endl << "Lecture end time: "; cin >> lecE;
		cout << endl << "Lab days (single letter): "; cin >> labD;
		cout << endl << "Lab start time: "; cin >> labS;
		cout << endl << "Lab end time: "; cin >> labE;
		cout << endl << "Semester: "; cin >> cSem;
		cout << endl << "Year: "; cin >> cYear;
		cout << endl << "Credits: "; cin >> cCredits;

		//Create course database entry
		string dataEntry("INSERT INTO STUDENT VALUES(" + cID + ",'" + cTitle + "', '" + cDept + "', '" + lecD + "', " + lecS + ", " + lecE + ", '" + labD + "', " + labS + ", " + labE + ", '" + cSem + "', " + cYear + ", " + cCredits + "); "
		);
		sqlite3_exec(DB, dataEntry.c_str(), callback, NULL, NULL);
		string printS1 = "SELECT * FROM COURSE WHERE CRN = ";
		string printS = printS1 + cID;
		cout << endl << printS;
		sqlite3_exec(DB, printS.c_str(), callback, NULL, &messageError);


	}
	else if (choice == 'b') {
		cout << "Enter CRN of class you would like to remove: "; cin >> courseID;
		string deleteC1 = "DELETE FROM COURSE WHERE CRN = ";
		string deleteC = deleteC1 + courseID;
		sqlite3_exec(DB, deleteC.c_str(), callback, NULL, &messageError);

		if (exit != SQLITE_OK)
		{
			std::cerr << "Error Removal" << std::endl;
			sqlite3_free(messageError);
		}
		else
			std::cout << "Records removed Successfully!" << std::endl;
	}
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
