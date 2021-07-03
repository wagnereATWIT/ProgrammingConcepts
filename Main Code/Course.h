//Course.h
#include <string>
#ifndef COURSE_H
#define COURSE_H

class Course {
public:
	// CONSTRUCTOR
	Course(int, const std::string&, const std::string&, const std::string&, int, int, const std::string&, int, int, const std::string&, int, int);
	//std::string toString() const;

	// SET FUNCTIONS
	void setCode(int);
	void setCourse(std::string);
	void setDepartment(std::string);

	void setLecDays(std::string);
	void setLecStart(int);
  void setLecEnd(int);
  
	void setLabDays(std::string);
 	void setLabStart(int);
  void setLabEnd(int);

	void setSemester(std::string);
	void setYear(int);
	void setCredits(int);

	// GET FUNCTIONS
	int getCode() const;
	std::string getCourse() const;
	std::string getDepartment() const;

	std::string getLecDays() const;
	int getLecStart() const;
  int setLecEnd() const;
  
	std::string getLabDays() const;
	int getLabStart() const;
  int setLabEnd() const;

	std::string getSemester() const;
	int getYear() const;
	int getCredits() const;

	//DESTRUCTOR
	~Course();

private:
	int courseCode;
	std::string nameOfCourse;
	std::string nameOfDepartment;
  std::string lecDays;
  int lecStart;
  int lecEnd;
  std::string labDays;
  int labStart;
  int labEnd;
	std::string semesterSeason;
	int semesterYear;
	int courseCredits;
};

#endif