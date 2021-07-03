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

    //Testing Instructor print roster
    vector<Instructor*> testInst;
    testInst.push_back(new Instructor("Kaycee", "Salgueiro", 20700, "BSEE");
    testInst[0]->printRoster();
    
    //Testing Admin Add/Remove course
    vector<Admin*> testAdmin;
    testAdmin.push_back(new Admin("Andy", "Wagner", 30500, "WENTW 001");
    testAdmin[0]->addRemoveCourse();

//        
//    //Print courses
//    string query = "SELECT * FROM COURSE;";
//    cout << endl << query << endl;		//print the string to screen
//    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
//    
//    //Print student (all and single)
//    query = "SELECT * FROM STUDENT;";
//    cout << endl << query << endl;		//print the string to screen
//    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
//
//    string student_idp;
//    cout << "Print single student" << endl;
//    cout << "Enter student ID: ";
//    cin >> student_idp;
//
//    string printS1 = "SELECT * FROM STUDENT WHERE ID = ";
//    string printS = printS1 + student_idp;
//    exit = sqlite3_exec(DB, printS.c_str(), callback, NULL, &messageError);
//
//    //Add student 1
//    string id, fname, lname, gradyear, major, email;
//    cout << "Add student" << endl;
//    cout << "Enter ID, first name, last name, expected graduation year, major, and email: ";
//    cin >> id >> fname >> lname >> gradyear >> major >> email;
//
//    string userInput("INSERT INTO STUDENT VALUES(" + id + ",'" + fname + "','" + lname + "'," + gradyear + ",'" + major + "','" + email + "');"
//    );
//    exit = sqlite3_exec(DB, userInput.c_str(), callback, NULL, NULL);
//
//    //Add student 2
//    cout << "Add student" << endl;
//    cout << "Enter ID, first name, last name, expected graduation year, major, and email: ";
//    cin >> id >> fname >> lname >> gradyear >> major >> email;
//
//    string userInput2("INSERT INTO STUDENT VALUES(" + id + ",'" + fname + "','" + lname + "'," + gradyear + ",'" + major + "','" + email + "');"
//    );
//    exit = sqlite3_exec(DB, userInput2.c_str(), callback, NULL, NULL);
//
//    query = "SELECT * FROM STUDENT;";
//    cout << endl << query << endl;		//print the string to screen
//    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
//
//    //Delete Instructor
//    query = "SELECT * FROM INSTRUCTOR;";
//    cout << endl << query << endl;		//print the string to screen
//    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
//    string instructor_idd;
//    cout << "Delete instructor" << endl;
//    cout << "Enter instructor ID: ";
//    cin >> instructor_idd;
//
//    string deleteI1 = "DELETE FROM INSTRUCTOR WHERE ID = ";
//    string deleteI = deleteI1 + instructor_idd;
//    exit = sqlite3_exec(DB, deleteI.c_str(), callback, NULL, &messageError);
//
//    query = "SELECT * FROM INSTRUCTOR;";
//    cout << endl << query << endl;		//print the string to screen
//    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
//    
//    //Edit Admin
//    query = "SELECT * FROM ADMIN;";
//    cout << endl << query << endl;		//print the string to screen
//    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
//    
//    string updateA = "UPDATE ADMIN SET TITLE = 'Vice-President' WHERE ID = 30002;";
//    cout << endl << updateA << endl;		//print the string to screen
//    exit = sqlite3_exec(DB, updateA.c_str(), callback, NULL, &messageError);
//    
//    query = "SELECT * FROM ADMIN;";
//    cout << endl << query << endl;		//print the string to screen
//    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
//    
//    //Flag professors that can teach the courses
//    string flagProf = "SELECT COURSE.TITLE, COURSE.LECTURE_DAYS, COURSE.LECTURE_START, COURSE.LECTURE_END, COURSE.LAB_DAYS, COURSE.LAB_START, COURSE.LAB_END FROM COURSE WHERE INSTRUCTOR.DEPT = COURSE.DEPT;";
//    cout << endl << "Roster: " << endl;
//    sqlite3_exec(DB, flagProf.c_str(), callback, NULL, NULL);

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