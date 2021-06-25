//Schedule.cpp
#include <iostream>
#include<sstream>
#include<string>
#include "Schedule.h"

using namespace std;

// CONSTRUCTOR
Schedule::Schedule(string day, int start, int end)
	:dayOfWeek{ day }, startTime{ start }, endTime{ checkTime(start, end) }
{}

// PRINT FUNCTION
string Schedule::toString() const 
{
	ostringstream output;
	output << "Day of the week: " << dayOfWeek << endl
		<< "Start time: " << ((startTime == 0 || startTime == 12) ? 12 : startTime % 12) << (startTime < 12 ? "AM" : "PM") << endl
		<< "End time: " << ((endTime == 0 || endTime == 12) ? 12 : endTime % 12) << (endTime < 12 ? "AM" : "PM") << endl;
	return output.str();
}

// SET FUNCTIONS
void Schedule::setDay(string day) 
{
	dayOfWeek = day;
}

void Schedule::setStart(int start) 
{
	startTime = convertTime(start);
}

void Schedule::setEnd(int end) 
{
	endTime = convertTime(end);
}
	

// GET FUNCTIONS
string Schedule::getDay() const { return dayOfWeek; }
int Schedule::getStart() const { return startTime; }
int Schedule::getEnd() const { return endTime; }

//MILITARY TO STANDARD TIME
int Schedule::convertTime(int hour)
{
	hour = ((hour == 0 || hour == 12) ? 12 : hour % 12);
	return hour;
}
//UTILITY FUNCTION
int Schedule::checkTime(int start, int end)
{
	int loop{ 1 };

	while (loop == 1) 
	{
		if ((end <= start))
		{
			int newEnd{ 0 };
			cout << "Invalid class end time." << endl;
			cout << "Start time is: " << start << " End time is: " << end << endl;
			cout << "Enter new end time: ";
			cin >> newEnd;
			end = newEnd;
		}
		else
		{
			loop = 0;
			return end;
		}
	}
	
}

// DESTRUCTOR
Schedule::~Schedule() {}
