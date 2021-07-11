#include <iostream> 
#include <string> 
#include <sqlite3.h> 
#include <stdio.h>
#include <vector>
#include "User.h"
//#include "Student.h"
#include "Instructor.h"
#include "Admin.h"

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
        "ID INTEGER PRIMARY KEY, "
        "FIRST_NAME TEXT NOT NULL, "
        "LAST_NAME TEXT NOT NULL, "
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
        "ID INTEGER PRIMARY KEY, "
        "FIRST_NAME TEXT NOT NULL, "
        "LAST_NAME TEXT NOT NULL, "
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
        "ID INTEGER PRIMARY KEY, "
        "FIRST_NAME TEXT NOT NULL, "
        "LAST_NAME TEXT NOT NULL, "
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
