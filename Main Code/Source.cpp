#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include <sstream>

#include "User.h"
#include "Admin.h"
#include "Student.h"
#include "Instructor.h"

#include "Course.h"
#include "Functions.h"

using namespace std;

string login(sqlite3*, std::vector<std::string>);

void menu_instructor(Instructor &I, sqlite3*);
void menu_admin(Admin &A, sqlite3*);
void menu_student(Student &S, sqlite3*);

Student create_student(sqlite3*, std::vector<std::string>, string);
Instructor create_instructor(sqlite3*, std::vector<std::string>, string);
Admin create_admin(sqlite3*, std::vector<std::string>, string);

int main(int argc, char** argv) {

	std::vector<std::string> container;
	string Q1;
	string Q2;

	string User_ID;

	sqlite3* DB;
	
	sqlite3_open("SystemDatabase.db", &DB);

	StudentDB(DB);
	InstructorDB(DB);
	AdminDB(DB);
	CourseDB(DB); 

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

    return 0;
}

string login(sqlite3* DB, std::vector<std::string> container) {
	string exit;
	string Q1;
	string Q2;
	string UN;
	string PW;

	cout << "Username (Id #): "; cin >> UN;
	cout << "Password: "; cin >> PW;

	Q1 = "SELECT * FROM STUDENT WHERE ID = ";
	Q2 = Q1 + UN;
	exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);

	Q1 = "SELECT * FROM INSTRUCTOR WHERE ID = ";
	Q2 = Q1 + UN;
	exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);

	Q1 = "SELECT * FROM ADMIN WHERE ID = ";
	Q2 = Q1 + UN;
	exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);

	return container[0];
}

Student create_student(sqlite3* DB, std::vector<std::string> container, string ID) {
	string first_name;
	string last_name;
	double gpa;
	int user_id;

	string Q1; string Q2; string exit;
	
	Q1 = "SELECT FIRST_NAME FROM STUDENT WHERE ID = ";
	Q2 = Q1 + ID;
	exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);
	first_name = container[0];

	Q1 = "SELECT LAST_NAME FROM STUDENT WHERE ID = ";
	Q2 = Q1 + ID;
	exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);
	last_name = container[1];

	Q1 = "SELECT GPA FROM STUDENT WHERE ID = ";
	Q2 = Q1 + ID;
	exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);
	std::string::size_type sz;
	gpa = std::stod(container[2], &sz);

	stringstream T(ID);
	T >> user_id;

	Student temp(first_name, last_name, user_id, gpa); 

	return temp;
}

Instructor create_instructor(sqlite3* DB, std::vector<std::string> container, string ID){
	string first_name;
	string last_name;
	string department;
	int user_id;

	string Q1; string Q2; string exit;

	Q1 = "SELECT FIRST_NAME FROM INSTRUCTOR WHERE ID = ";
	Q2 = Q1 + ID;
	exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);
	first_name = container[0];

	Q1 = "SELECT LAST_NAME FROM INSTRUCTOR WHERE ID = ";
	Q2 = Q1 + ID;
	exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);
	last_name = container[1];

	Q1 = "SELECT DEPARTMENT FROM INSTRUCTOR WHERE ID = ";
	Q2 = Q1 + ID;
	exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);
	department = container[2];

	stringstream T(ID);
	T >> user_id;

	Instructor temp(first_name, last_name, user_id, department);

	return temp;
}

Admin create_admin(sqlite3* DB, std::vector<std::string> container, string ID) {
	string first_name;
	string last_name;
	string office;
	int user_id;

	string Q1; string Q2; string exit;

	Q1 = "SELECT FIRST_NAME FROM ADMIN WHERE ID = ";
	Q2 = Q1 + ID;
	exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);
	first_name = container[0];

	Q1 = "SELECT LAST_NAME FROM ADMIN WHERE ID = ";
	Q2 = Q1 + ID;
	exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);
	last_name = container[1];

	Q1 = "SELECT OFFICE FROM ADMIN WHERE ID = ";
	Q2 = Q1 + ID;
	exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);
	office = container[2];

	stringstream T(ID);
	T >> user_id;

	Admin temp(first_name, last_name, user_id, office);

	return temp;
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
	vector<Course> Schedule;
	int loop = 0;
	char choice;
	while (loop == 0) {
		cout << "------Menu------" << endl;
		cout << "s - Course Search " << endl
			<< "a - Add/Remove Courses (schedule)" << endl
			<< "p - Print Schedule" << endl
			<< "x - Log-out" << endl;
		cin >> choice;
		switch (choice) {
		case 's':
			// Call Course Search Function
			S.searchCourse(DB);
			break;
		case 'a':
			// Call Add/Remove Courses (schedule)
			Schedule = S.addDropCourse(DB, Schedule);  
			break;
		case 'p':
			S.printSchedule(Schedule);
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