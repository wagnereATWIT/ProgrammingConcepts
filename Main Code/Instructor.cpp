//Instructor.cpp
#include "User.h"
#include "User.cpp"
#include "Instructor.h"
#include "Functions.h"
#include "Functions.cpp"
#include <sqlite3.h> 
#include <iostream>
#include <string> 
#include <stdio.h>

using namespace std;

//CONSTRUCTOR
Instructor::Instructor(string fName, string lName, int ID, string school)
	:User{ fName, lName, ID }
{
	this->schoolType = school;
}

//FUNCTIONS
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

void Instructor::printRoster()
{
  sqlite3* DB;
  string department;
  cout << endl << "Enter your four-letter department name: " << endl;
  cin >> department;
	//Flag professors that can teach the courses
  string flagProf_1 = "SELECT COURSE.TITLE, COURSE.LECTURE_DAYS, COURSE.LECTURE_START, COURSE.LECTURE_END, COURSE.LAB_DAYS, COURSE.LAB_START, COURSE.LAB_END FROM COURSE WHERE COURSE.DEPT = ";
  string flagProf = flagProf_1 + department;
  cout << endl << "Roster: " << endl;
  sqlite3_exec(DB, flagProf.c_str(), callback, NULL, NULL);
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
