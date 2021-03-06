//Admin.h
#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <sstream>
#include <string>

#include "User.h"

class Admin : public User
{
public:
	//CONSTRUCTOR
	Admin(std::string, std::string, int, std::string);

	//FUNCTIONS
	virtual std::string toString() const;
	void setOffice(std::string);
	std::string getOffice() const;
	void addRemoveCourse(sqlite3*); 
	void addRemoveUser();
	void LinkUser();
	void searchRoster();
	void printRoster() const;
	void printCourse() const;

	//DESTRUCTOR
	~Admin();

private:
	std::string adOffice;
};

#endif
