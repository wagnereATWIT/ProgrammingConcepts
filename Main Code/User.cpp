#include <iostream>
#include <sstream>
#include <string>
#include "User.h"

using namespace std;
//CONSTRUCTOR
User::User(string fName, string lName, int ID)
	:firstName{ fName }, lastName{ lName }, userID{ ID }
{
	cout << "Constructor called for User" << endl;
}

//SET FUNCTIONS
void User::setFirstName(string fName)
{
	firstName = fName;
}

void User::setLastName(string lName)
{
	lastName = lName;
}

void User::setID(int ID)
{
	userID = ID;
}

//GET FUNCTIONS
string User::getFirstName() const
{
	return firstName;
}

string User::getLastName() const
{
	return lastName;
}

int User::getID() const
{
	return userID;
}

//DESTRUCTOR
User::~User()
{
	cout << "Destructor for User called" << endl;
}
