//Instructor.h
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <iostream>
#include <sstream>
#include <string>

#include "User.h"

class Instructor : public User
{
public:
	//CONSTRUCTOR
	Instructor(std::string, std::string, int, std::string);

	//FUNCTIONS
	virtual std::string toString() const;
	void setSchool(std::string);
	std::string getSchool() const;
	void printRoster(sqlite3*);
	void printSchedule() const;

	//DESTRUCTOR
	~Instructor();

private:
	std::string schoolType;
};

#endif
