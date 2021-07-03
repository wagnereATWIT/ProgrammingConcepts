#include "Functions.h"
#include <vector>
#include <string>
#include <iostream> 
#include <sqlite3.h> 
#include <stdio.h>
//#include "User.h"
//#include "User.cpp"
//#include "Student.h"
//#include "Student.cpp"
//#include "Instructor.h"
//#include "Instructor.cpp"
//#include "Admin.h"
//#include "Admin.cpp" 
#include "Course.h"
#include "Course.cpp" 

using namespace std;

int callback(void* data, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void courseCreation(vector<Course*> &list, int ID, string title, string major, string lecD, int lecS, int lecE, string labD, int labS, int labE, string semester, int year, int credits){
  sqlite3* DB;
  int exit = 0;
  exit = sqlite3_open("SystemDatabase.db", &DB);			//open the database
  char* messageError;
// add courses into database and objects
    int courseID = ID;
    string courseTitle = title;
    string courseMajor = major;
    string lecDays = lecD;
    int lecStart = lecS;
    int lecEnd = lecE;
    string labDays = labD;
    int labStart = labS;
    int labEnd = labE;
    string courseSem = semester;
    int courseYear = year;
    int courseCredits = credits;
    
    string courseID_S = to_string(courseID);
    string lecStart_S = to_string(lecStart);
    string lecEnd_S  = to_string(lecEnd);
    string labStart_S = to_string(labStart);
    string labEnd_S = to_string(labEnd);
    string courseYear_S = to_string(courseYear);
    string courseCredits_S = to_string(courseCredits);

  //Insert into database
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
        
     //Create object
    list.push_back(new Course(courseID, courseTitle, courseMajor, lecDays, lecStart, lecEnd, labDays, labStart, labEnd, courseSem, courseYear, courseCredits));
}

  vector<Course*> mainCourseList;
  
//int main() {
//
//  courseCreation(mainCourseList, 50200, "NETWORK THEORY I", "BSEE", "TR", 8, 9, "M", 12, 2, "FALL", 2021, 4);
//  courseCreation(mainCourseList, 50201, "NETWORK THEORY II", "BSEE", "MW", 10, 11, "T", 2, 4, "FALL", 2021, 4);
//  courseCreation(mainCourseList, 50202, "APPLIED PROGRAMMING CONCEPTS", "BSCO", "M", 8, 9, "TR", 8, 10, "SUMMER", 2021, 4);
//}