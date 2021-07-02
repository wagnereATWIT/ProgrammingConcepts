//Instructor.cpp
#include "User.h"
#include "Instructor.h"
#include <sqlite3.h> 
#include <iostream>
#include <string> 
#include <stdio.h>

using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;

    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");

    return 0;
}

int main(int argc, char** argv){}

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

void Instructor::printRoster() const
{
  sqlite3* DB;
	//Flag professors that can teach the courses
  string flagProf = "SELECT COURSE.TITLE, COURSE.LECTURE_DAYS, COURSE.LECTURE_START, COURSE.LECTURE_END, COURSE.LAB_DAYS, COURSE.LAB_START, COURSE.LAB_END FROM COURSE WHERE INSTRUCTOR.DEPT = COURSE.DEPT;";
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
