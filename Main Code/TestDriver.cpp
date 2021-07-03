//Created by Kaycee Salgueiro
#include <iostream> 
#include <string> 
#include <sqlite3.h> 
#include <stdio.h>
#include <vector>
#include "User.h"
//#include "User.cpp"
//#include "Student.h"
//#include "Student.cpp"
#include "Instructor.h"
#include "Instructor.cpp"
//#include "Admin.h"
//#include "Admin.cpp" 

using namespace std;


int main(int argc, char** argv)
{
    sqlite3* DB;
    
    //Create course table
    string course = "CREATE TABLE COURSE("
        "CRN INTEGER PRIMARY KEY, "
        "TITLE TEXT NOT NULL, "
        "DEPARTMENT TEXT NOT NULL, "
        "LECTURE_DAYS TEXT NOT NULL, "
        "LECTURE_START INTEGER NOT NULL, "
        "LECTURE_END INTEGER NOT NULL, "
        "LAB_DAYS TEXT,"
        "LAB_START INTEGER, "
        "LAB_END INTEGER, "
        "SEMESTER TEXT NOT NULL, "
        "YEAR INTEGER NOT NULL,"
        "CREDITS INTEGER NOT NULL); ";
        
     int exit = 0;

    exit = sqlite3_open("SystemDatabase.db", &DB);			//open the database

    char* messageError;

    // execute the create table command
    exit = sqlite3_exec(DB, course.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Table created Successfully" << std::endl;


    //Create Student table
    string student = "CREATE TABLE STUDENT("
        "FIRST_NAME TEXT NOT NULL, "
        "LAST_NAME TEXT NOT NULL, "
        "ID INTEGER PRIMARY KEY, "
        "GPA REAL NOT NULL); ";
        
     exit = 0;

    exit = sqlite3_open("SystemDatabase.db", &DB);			//open the database

    messageError;

    // execute the create table command
    exit = sqlite3_exec(DB, student.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Table created Successfully" << std::endl;

        
    //Create Instructor table
    string instructor = "CREATE TABLE INSTRUCTOR("
        "FIRST_NAME TEXT NOT NULL, "
        "LAST_NAME TEXT NOT NULL, "
        "ID INTEGER PRIMARY KEY, "
        "DEPARTMENT TEXT NOT NULL); ";
        
    exit = 0;

    exit = sqlite3_open("SystemDatabase.db", &DB);			//open the database

    messageError;

    // execute the create table command
    exit = sqlite3_exec(DB, instructor.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Table created Successfully" << std::endl;

        
    //Create Admin table
    string admin = "CREATE TABLE ADMIN("
        "FIRST_NAME TEXT NOT NULL, "
        "LAST_NAME TEXT NOT NULL, "
        "ID INTEGER PRIMARY KEY, "
        "OFFICE TEXT NOT NULL); ";

    exit = 0;

    exit = sqlite3_open("SystemDatabase.db", &DB);			//open the database

    messageError;

    // execute the create table command
    exit = sqlite3_exec(DB, admin.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Table created Successfully" << std::endl;
		
	cout << "-----Log in-----" << endl;
	User_ID = login(DB);

    //Testing Student Add/Drop course
    Student testStud{"Andy", "Wagner", 10500, 3.70};
    testStud.addDropCourse();

    //Testing Instructor print roster
    Instructor testInst{"Kaycee", "Salgueiro", 20500, "BSEE"};
    testInst.printRoster();
    
    //Testing Admin Add/Remove course
    Admin testAd{"Kaycee", "Salgueiro", 20500, "WENTW 001"};
    testAd.addRemoveCourse();

    return 0;
}
//Created by Andy Wager
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
