#include <iostream>
#include <stdio.h>
#include <sqlite3.h>

#include "User.h"
#include "Admin.h"
#include "Student.h"
#include "Instructor.h"

#include "Course.h"
#include "Schedule.h"
#include "Functions.h"

using namespace std;

string login(sqlite3*);

void menu_instructor(Instructor &I, sqlite3*);
void menu_admin(Admin &A, sqlite3*);
void menu_student(Student &S, sqlite3*);

int main(int argc, char** argv) {
	string User_ID;
	char* messageError;
	sqlite3* DB;
	sqlite3_open("assignment3.db", &DB);

	//Print student (all)
	string query = "SELECT * FROM STUDENT;";
	cout << endl << query << endl;		//print the string to screen
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);


	cout << "-----Log in-----" << endl;
	User_ID = login(DB);
	Student S("Student", "Man", 00000, 3.0);

	menu_student(S, DB); 

    return 0;
}


string login(sqlite3* DB) {
	char* messageError;
	string UN;
	string PW;
	bool loop = 1;

	do {
		cout << "Username (Id #): "; cin >> UN;
		cout << "Password: "; cin >> PW;

		string query = "SELECT * FROM STUDENT WHERE ID = ";
		string queryS = query + UN;
		sqlite3_exec(DB, queryS.c_str(), callback, NULL, &messageError);

		query = "SELECT * FROM INSTRUCTOR WHERE ID = ";
		queryS = query + UN;
		sqlite3_exec(DB, queryS.c_str(), callback, NULL, &messageError);

		query = "SELECT * FROM ADMIN WHERE ID = ";
		queryS = query + UN;
		sqlite3_exec(DB, queryS.c_str(), callback, NULL, &messageError);

	} while (loop == 0);

	return UN;
}

void menu_admin(Admin& A, sqlite3* DB) {

	int loop = 0;
	char choice;
	while (loop == 0) {
		cout << "------Menu------" << endl;
		cout << "s - Course Search " << endl
			<< "a - Add/Remove Courses (system)" << endl
			<< "x - Log-out" << endl;
		cin >> choice;
		switch (choice) {
		case 's':
			// Call Course Search Function
			A.searchCourse(DB);
			break;
		case 'a':
			// Call Add/Remove Courses (system)
			A.addRemoveCourse();
			break;
		case 'x':
			cout << "Logging out..." << endl;
			loop = 1;
		}
	}
}

void menu_student(Student& S, sqlite3* DB) {

	int loop = 0;
	char choice;
	while (loop == 0) {
		cout << "------Menu------" << endl;
		cout << "s - Course Search " << endl
			<< "a - Add/Remove Courses (schedule)" << endl
			<< "x - Log-out" << endl;
		cin >> choice;
		switch (choice) {
		case 's':
			// Call Course Search Function
			S.searchCourse(DB);
			break;
		case 'a':
			// Call Add/Remove Courses (schedule)
			S.addDropCourse();
			break;
		case 'x':
			cout << "Logging out..." << endl;
			loop = 1;
		}
	}
}

void menu_instructor(Instructor& I, sqlite3* DB) {

	int loop = 0;
	char choice;
	while (loop == 0) {
		cout << "------Menu------" << endl;
		cout << "s - Course Search " << endl
			<< "r - Course Roster" << endl
			<< "x - Log-out" << endl;
		cin >> choice;
		switch (choice) {
		case 's':
			// Call Course Search Function
			I.searchCourse(DB);
			break;
		case 'r':
			// Call Course Roster
			I.printRoster();
			break;
		case 'x':
			cout << "Logging out..." << endl;
			loop = 1;
		}
	}
}