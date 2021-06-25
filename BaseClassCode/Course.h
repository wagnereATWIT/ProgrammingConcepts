//Course.h
#include <string>
#include "Schedule.h"
#ifndef COURSE_H
#define COURSE_H

class Course {
public:
	// CONSTRUCTOR
	Course(int, const std::string&, const std::string&, Schedule&, Schedule&, Schedule&, const std::string&, int, int);
	//std::string toString() const;

	// SET FUNCTIONS
	void setCode(int);
	void setCourse(std::string);
	void setDepartment(std::string);

	void setLec1(Schedule&);
	void setLec2(Schedule&);
	void setLab(Schedule&);

	void setSemester(std::string);
	void setYear(int);
	void setCredits(int);

	// GET FUNCTIONS
	int getCode() const;
	std::string getCourse() const;
	std::string getDepartment() const;

	Schedule& getLec1();
	Schedule& getLec2();
	Schedule& getLab();

	std::string getSemester() const;
	int getYear() const;
	int getCredits() const;

	//DESTRUCTOR
	~Course();

private:
	int courseCode;
	std::string nameOfCourse;
	std::string nameOfDepartment;
	Schedule lectureOneSchedule;
	Schedule lectureTwoSchedule;
	Schedule labSchedule;
	std::string semesterSeason;
	int semesterYear;
	int courseCredits;
};

#endif