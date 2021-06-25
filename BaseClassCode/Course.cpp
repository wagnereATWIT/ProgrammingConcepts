#include <iostream>
#include<sstream>
#include<string>
#include "Course.h"
#include "Schedule.h"

using namespace std;

// CONSTRUCTOR
Course::Course(int CRN, const string& courseName, const string& department, Schedule& Lec1, Schedule& Lec2, Schedule& Lab, const string& semester, int year, int credits)
	: courseCode{ CRN }, nameOfCourse{ courseName }, nameOfDepartment{ department },
	lectureOneSchedule{ Lec1 }, lectureTwoSchedule{ Lec2 }, labSchedule{ Lab }, 
	semesterSeason{ semester }, semesterYear{ year }, courseCredits{ credits }
{}

//// PRINT FUNCTION
//string Course::toString() const {
//	ostringstream output;
//	output << nameOfCourse << " ( " << courseCode << " ) " << endl
//		<< "Instuctor: " << nameOfInstructor << endl
//		<< "Credits: " << credits << endl
//		<< "Lecture 1 Schedule: " << endl << lectureOneSchedule.toString() << endl
//		<< "Lecture 2 Schedule: " << endl << lectureTwoSchedule.toString() << endl
//		<< "Lab Schedule: " << endl << labSchedule.toString() << endl;
//	return output.str();
//}

// SET FUNCTIONS
void Course::setCode(int CRN)
{
	courseCode = CRN;
}

void Course::setCourse(string courseName) {
	nameOfCourse = courseName;
}

void Course::setDepartment(string department) 
{
	nameOfDepartment = department;
}

void Course::setLec1(Schedule& Lec1) 
{
	lectureOneSchedule = Lec1;
}

void Course::setLec2(Schedule& Lec2) 
{
	lectureTwoSchedule = Lec2;
}

void Course::setLab(Schedule& Lab) 
{
	labSchedule = Lab;
}

void Course::setSemester(string semester)
{
	semesterSeason = semester;
}

void Course::setYear(int year)
{
	semesterYear = year;
}

void Course::setCredits(int credits)
{
	courseCredits = credits;
}

// GET FUNCTIONS
int Course::getCode() const { return courseCode; }
string Course::getCourse() const { return nameOfCourse; }
string Course::getDepartment() const { return nameOfDepartment; }

Schedule& Course::getLec1() { return lectureOneSchedule; }
Schedule& Course::getLec2() { return lectureTwoSchedule; }
Schedule& Course::getLab() { return labSchedule; }

string Course::getSemester() const { return semesterSeason; }
int Course::getYear() const { return semesterYear; }
int Course::getCredits() const { return courseCredits; }

//DESTRUCTOR
Course::~Course() {}