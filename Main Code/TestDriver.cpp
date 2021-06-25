#include <iostream> 
#include <sqlite3.h> 
#include <string> 
#include <stdio.h>

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
        "LECTURE_1 TEXT NOT NULL, "
        "LECTURE_2 TEXT NOT NULL, "
        "LAB TEXT,"
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
        "GPA REAL NOT NULL, ";
        
     int exit = 0;

    exit = sqlite3_open("SystemDatabase.db", &DB);			//open the database

    char* messageError;

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
        "DEPARTMENT TEXT NOT NULL, ";
        
     int exit = 0;

    exit = sqlite3_open("SystemDatabase.db", &DB);			//open the database

    char* messageError;

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
        "OFFICE TEXT NOT NULL, ";

    int exit = 0;

    exit = sqlite3_open("SystemDatabase.db", &DB);			//open the database

    char* messageError;

    // execute the create table command
    exit = sqlite3_exec(DB, admin.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Table created Successfully" << std::endl;


//    // add values into database
//    string course_insert("INSERT INTO COURSE VALUES(13205, 'NETWORK THEORY I', 'BSEE', '12:20PM-1:50PM', 'TR', 'FALL', 2021, 4);"
//        "INSERT INTO COURSE VALUES(14887, 'SIGNALS AND SYSTEMS', 'BSEE', '9:30AM-10:50AM', 'MW', 'FALL', 2021, 4);"
//        "INSERT INTO COURSE VALUES(13778, 'ENVIORNMENTAL ENGINEERING', 'BSCE', '8:00AM-9:20AM', 'TRF', 'FALL', 2021, 4);"
//        "INSERT INTO COURSE VALUES(32401, 'COMPUTER ARCHITECTURE', 'BSCO', '5:30PM-8:30PM', 'R', 'SUMMER', 2021, 3);"
//        "INSERT INTO COURSE VALUES(32380, 'ELECTROMAGNETIC FIELD THEORY', 'BSME',  '9:30AM-10:50AM', 'WF', 'SUMMER', 2021, 3);"
//
//    );
//
//    // execute the command
//    exit = sqlite3_exec(DB, course_insert.c_str(), NULL, 0, &messageError);
//
//    if (exit != SQLITE_OK)
//    {
//        std::cerr << "Error Insert" << std::endl;
//        sqlite3_free(messageError);
//    }
//    else
//        std::cout << "Records created Successfully!" << std::endl;
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
//    string flagProf = "SELECT COURSE.TITLE, INSTRUCTOR. NAME, INSTRUCTOR.SURNAME FROM COURSE, INSTRUCTOR WHERE INSTRUCTOR.DEPT = COURSE.DEPT;";
//    cout << endl << "Courses Matched with instructors" << endl;
//    sqlite3_exec(DB, flagProf.c_str(), callback, NULL, NULL);

    return 0;
}