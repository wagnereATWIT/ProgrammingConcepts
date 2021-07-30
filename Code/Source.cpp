#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include <sstream>

#include "User.h"
#include "Admin.h"
#include "Student.h"
#include "Instructor.h"
#include "MenuFunctions.h"

#include "Course.h"
#include "Functions.h"

using namespace std;

int main(int argc, char** argv) {

	std::vector<std::string> container;
	string Q1;
	string Q2;
	bool loop = false;
	int choice; 
	string User_ID;

	sqlite3* DB;
	
	sqlite3_open("SystemDatabase.db", &DB);

	StudentDB(DB);
	InstructorDB(DB);
	AdminDB(DB);
	CourseDB(DB); 

	while (loop == false) {
		cout << "Registration System" << endl;
		cout << "1 - login" << endl << "2 - Reset Database" << endl << "3 - exit" << endl;
		cin >> choice;
		if (choice == 1) {
			cout << "-----Log in-----" << endl;
			User_ID = login(DB, container);
			if (User_ID[0] == '1') {
				cout << endl << "STUDENT" << endl;

				Q1 = "SELECT * FROM STUDENT WHERE ID = ";
				Q2 = Q1 + User_ID;
				sqlite3_exec(DB, Q2.c_str(), callback, NULL, NULL);			// print user information

				Student S = create_student(DB, container, User_ID);			// create object of type student
				menu_student(S, DB);										// open student menu
			}
			else if (User_ID[0] == '2') {
				cout << endl << "INSTUCTOR" << endl;

				Q1 = "SELECT * FROM INSTRUCTOR WHERE ID = ";
				Q2 = Q1 + User_ID;
				sqlite3_exec(DB, Q2.c_str(), callback, NULL, NULL);			// print user information

				Instructor I = create_instructor(DB, container, User_ID);	// create object of type instructor
				menu_instructor(I, DB);										// open instructor menu
			}
			else if (User_ID[0] == '3') {
				cout << endl << "ADMIN" << endl;

				Q1 = "SELECT * FROM ADMIN WHERE ID = ";
				Q2 = Q1 + User_ID;
				sqlite3_exec(DB, Q2.c_str(), callback, NULL, NULL);			// print user information

				Admin A = create_admin(DB, container, User_ID);					// create object of type admin
				menu_admin(A, DB);											// open admin menu
			}
		}
		else if (choice == 2) {
			ResetDB(DB); 
			StudentDB(DB);
			InstructorDB(DB);
			AdminDB(DB);
			CourseDB(DB);
			cout << "Database Reset..." << endl;
		}
		else if (choice == 3) {
			loop = true;
		}
	}

    return 0;
}