//Admin.cpp
#include "User.h"
#include "User.cpp"
#include "Admin.h"
#include "Functions.h"
#include "Functions.cpp"
#include <vector>
#include <string>
#include <iostream> 
#include <sqlite3.h> 
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
  sqlite3* DB;
  int exit = 0;
  exit = sqlite3_open("SystemDatabase.db", &DB);			//open the database
  char* messageError;
	char choice;
 string courseID;
  int cID;
  string cTitle;
  string cMajor;
  string lecD;
  int lecS;
  int lecE;
  string labD;
  int labS;
  int labE;
  string cSem;
  int cYear;
  int cCredits;

	cout << "Would you like to add or drop a course?: " << endl
		<< "a - add" << endl
		<< "b - drop" << endl;
	cin >> choice; 
	if (choice == 'a') {
    cout << endl << "Enter the following info for the class you would like to add "; cin >> cID;
		cout << endl << "CRN: "; cin >> cID;
    cout << endl <<"Title: "; cin >> cTitle;
    cout << endl << "Major (four letter): "; cin >> cMajor;
    cout << endl << "Lecture days (single letter): "; cin >> lecD;
    cout << endl << "Lecture start time: "; cin >> lecS;
    cout << endl << "Lecture end time: "; cin >> lecE;
    cout << endl << "Lab days (single letter): "; cin >> labD;
    cout << endl << "Lab start time: "; cin >> labS;
    cout << endl << "Lab end time: "; cin >> labE;
    cout << endl << "Semester: "; cin >> cSem;
    cout << endl << "Year: "; cin >> cYear;
    cout << endl << "Credits: "; cin >> cCredits;
    
    //Create course object and database entry
    courseCreation(mainCourseList, cID, cTitle, cMajor, lecD, lecS, lecE, labD, labS, labE, cSem, cYear, cCredits);
   

	}
	else if (choice == 'b'){
	  cout << "Enter CRN of class you would like to remove: "; cin >> courseID;
    string deleteC1 = "DELETE FROM COURSE WHERE CRN = ";
    string deleteC = deleteC1 + courseID;
    exit = sqlite3_exec(DB, deleteC.c_str(), callback, NULL, &messageError);
    
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
