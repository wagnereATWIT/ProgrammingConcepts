#include <iostream> 
#include <string> 
#include <sqlite3.h> 
#include <stdio.h>
#include "User.h"
#include "Student.h"
#include "Instructor.h"
#include "Admin.h" 
#include "Course.h"
#include "Course.cpp" 

using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;

    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");

    return 0;
}

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


    // add courses into database and objects
    int courseID = 50200;
    int lecStart = 8;
    int lecEnd = 9;
    int labStart = 12;
    int labEnd = 2;
    int courseYear = 2021;
    int courseCredits = 4;
    string courseTitle = "NETWORK THEORY I";
    string courseMajor = "BSEE";
    string lecDays = "TR";
    string labDays = "M";
    string courseSem = "FALL";
    
    string courseID_S = to_string(courseID);
    string lecStart_S = to_string(lecStart);
    string lecEnd_S  = to_string(lecEnd);
    string labStart_S = to_string(labStart);
    string labEnd_S = to_string(labEnd);
    string courseYear_S = to_string(courseYear);
    string courseCredits_S = to_string(courseCredits);


    string courseInsert("INSERT INTO COURSE VALUES(" + courseID_S + ",'" + courseTitle + "','" + courseMajor + "','" + lecDays + "'," + lecStart_S + "," + lecEnd_S + ",'" + labDays + "'," + labStart_S + "," + labEnd_S + ",'" + courseSem + "'," + courseYear_S + "," + courseCredits_S + ");");

    // execute the command
    exit = sqlite3_exec(DB, courseInsert.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;
        
     //Create object for course   
    Course netTheoryI(courseID, courseTitle, courseMajor, lecDays, lecStart, lecEnd, labDays, labStart, labEnd, courseSem, courseYear, courseCredits);
    cout << endl << "Network Theory I Code: " << netTheoryI.getCode() << endl;
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
