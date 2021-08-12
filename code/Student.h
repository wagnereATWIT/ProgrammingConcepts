//Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <sqlite3.h>
#include <string>

#include "User.h"
#include "Course.h"

class Student : public User
{
public:
	//CONSTRUCTOR
	Student(std::string, std::string, int, double);

	//FUNCTIONS
	virtual std::string toString() const;
	void setGPA(double);
	double getGPA() const;
	std::vector<Course> addDropCourse(sqlite3*, std::vector<Course>);
	void printSchedule(std::vector<Course>) const;

	bool checkConflict(sqlite3*, std::vector<Course>, Course*, int);

	//DESTRUCTOR
	~Student();

private:
	double studentGPA;
};

#endif
