//Created by Kaycee Salgueiro
//User.h
#ifndef USER_H
#define USER_H

#include <iostream>
#include <sstream>
#include <string>

#include "sqlite3.h"
#include "Functions.h"

class User { 
public:
	//CONSTRUCTOR
	User(std::string, std::string, int);
	virtual std::string toString() const = 0;

	void searchCourse(sqlite3*); 

	//SET FUNCTIONS
	void setFirstName(std::string);
	void setLastName(std::string);
	void setID(int);

	//GET FUNCTIONS
	std::string getFirstName() const;
	std::string getLastName() const;
	int getID() const;

	//DESTRUCTOR
	~User();

private:
	std::string firstName;
	std::string lastName;
	int userID;

};

#endif
