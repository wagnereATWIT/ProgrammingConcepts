//Schedule.h
#include <string>
#ifndef SCHEDULE_H
#define SCHEDULE_H



class Schedule {
public:
	// CONSTRUCTOR
	Schedule(std::string, int, int);
	std::string toString() const;

	// SET FUNCTIONS
	void setDay(std::string);
	void setStart(int);
	void setEnd(int);

	// GET FUNCTIONS
	std::string getDay() const;
	int getStart() const;
	int getEnd() const;

	// DESTRUCTOR
	~Schedule();

private:
	std::string dayOfWeek;
	int startTime;
	int endTime;
	//Convert military to standard time
	int convertTime(int);
	//Utility function to check endTime
	int checkTime(int, int);
};

#endif
