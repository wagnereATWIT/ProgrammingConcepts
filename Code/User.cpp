// User.cpp

#include "User.h"
using namespace std;

//CONSTRUCTOR
User::User(string fName, string lName, int ID)
	:firstName{ fName }, lastName{ lName }, userID{ ID }
{
	/*cout << "Constructor called for User" << endl;*/
}

void User::searchCourse(sqlite3* DB)
{
	char* messageError;
	string input;
	string Q1;
	string Q2;
	int exit = 0;

	int loop = 0;
	char choice;
	while (loop == 0) {
		cout << "------Menu------" << endl;
		cout << "c - Search by CRN " << endl
			<< "t - Search by Title" << endl
			<< "d - Search by Department" << endl
			<< "a - Show all Courses" << endl
			<< "x - Back" << endl;
		cin >> choice;

		if (choice == 'c') { // --------------------------------------------------------------WORKING (SEARCH BY CRN)
			cout << "Enter CRN: "; cin >> input;
			Q1 = "SELECT * FROM COURSE WHERE CRN = ";
			Q2 = Q1 + input;
			exit = sqlite3_exec(DB, Q2.c_str(), callback, NULL, &messageError);
		}
		else if (choice == 't') {	// -------------------------------------------------------WORKING (SEARCH BY TITLE)
			cout << "Enter Title: "; cin.ignore();  getline(cin, input);
			Q1 = "SELECT * FROM COURSE WHERE TITLE = ";
			Q2 = Q1 + '"' + input + '"'; 
			exit = sqlite3_exec(DB, Q2.c_str(), callback, NULL, &messageError);
		}
		else if (choice == 'd') {	// -------------------------------------------------------WORKING (SEARCH BY DEPARTMENT)
			cout << "Enter Department: "; cin >> input;
			Q1 = "SELECT * FROM COURSE WHERE DEPARTMENT = ";
			Q2 = Q1 + '"' + input + '"';
			exit = sqlite3_exec(DB, Q2.c_str(), callback, NULL, &messageError);
		}
		else if (choice == 'a') {	// -------------------------------------------------------WORKING (PRINT ALL COURSES)
			Q1 = "SELECT * FROM COURSE;";
			exit = sqlite3_exec(DB, Q1.c_str(), callback, NULL, &messageError);
		}
		else if (choice == 'x'){
			loop = 1;
		}
	}

	cout << "Exiting Search..." << endl;
}

//SET & GET FUNCTIONS
void User::setFirstName(string fName) { firstName = fName; }
void User::setLastName(string lName) { lastName = lName; }
void User::setID(int ID) { userID = ID; }

string User::getFirstName() const { return firstName; }
string User::getLastName() const { return lastName; }
int User::getID() const { return userID; }

//DESTRUCTOR
User::~User()
{}