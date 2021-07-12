//Instructor.cpp
#include "Instructor.h"
#include "Functions.h"
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

void Instructor::printRoster(sqlite3* DB)
{
	string department;
	cout << endl << "Enter your four-letter department name: ";
	cin >> department;
	//Flag professors that can teach the courses
	string flagProf_1 = "SELECT COURSE.TITLE, COURSE.LECTURE_DAYS, COURSE.LECTURE_START, COURSE.LECTURE_END, COURSE.LAB_DAYS, COURSE.LAB_START, COURSE.LAB_END FROM COURSE WHERE COURSE.DEPARTMENT = ";
	string flagProf = flagProf_1 + '"' + department + '"';
	cout << endl << "Roster: " << endl;
	sqlite3_exec(DB, flagProf.c_str(), callback, NULL, NULL);
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
