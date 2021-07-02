//Student.h
#include <string>
#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"

class Student : public User
{
public:
	//CONSTRUCTOR
	Student(std::string, std::string, int, double);

	//FUNCTIONS
	virtual std::string toString() const;
	void setGPA(double);
	double getGPA() const;
	void searchCourse();
	void addDropCourse();
	void printSchedule() const;

	//DESTRUCTOR
	~Student();

private:
	double studentGPA;
};

#endif
