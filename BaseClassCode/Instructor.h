//Instructor.h
#include <string>
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
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
	void searchCourse();
	void printRoster() const;
	void printSchedule() const;

	//DESTRUCTOR
	~Instructor();

private:
	std::string schoolType;
};

#endif