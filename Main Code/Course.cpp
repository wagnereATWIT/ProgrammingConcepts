//Created by Kaycee Salgueiro
#include <iostream>
#include<sstream>
#include<string>
#include "Course.h"

using namespace std;

// CONSTRUCTOR
Course::Course(int CRN, const string& courseName, const string& department, const string& lecDays, int lecStart, int lecEnd, const string& labDays, int labStart, int labEnd, const string& semester, int year, int credits)
	: courseCode{ CRN }, nameOfCourse{ courseName }, nameOfDepartment{ department },
	lecDays{ lecDays }, lecStart{ lecStart }, lecEnd{ lecEnd }, 
  labDays{ labDays }, labStart{ labStart }, labEnd{ labEnd }, 
	semesterSeason{ semester }, semesterYear{ year }, courseCredits{ credits }
{}

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

void Course::setLecDays(string lecDays) 
{
	lecDays = lecDays;
}

void Course::setLecStart(int lecStart) 
{
	lecStart = lecStart;
}

void Course::setLecEnd(int lecEnd) 
{
	lecEnd = lecEnd;
}

void Course::setLabDays(string labDays) 
{
	labDays = labDays;
}

void Course::setLabStart(int labStart) 
{
	labStart = labStart;
}

void Course::setLabEnd(int labEnd) 
{
	labEnd = labEnd;
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

string Course::getLecDays() const { return lecDays; }
int Course::getLecStart() const { return lecStart; }
int Course::setLecEnd() const { return lecEnd; }
  
string Course::getLabDays() const { return labDays; }
int Course::getLabStart() const { return labStart; }
int Course::setLabEnd() const { return labEnd; }

string Course::getSemester() const { return semesterSeason; }
int Course::getYear() const { return semesterYear; }
int Course::getCredits() const { return courseCredits; }

//DESTRUCTOR
Course::~Course() {}
