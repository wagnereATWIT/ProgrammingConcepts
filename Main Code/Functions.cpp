#include "Functions.h"
using namespace std;

int callback(void* data, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int callback_store(void* data, int argc, char** argv, char** azColName) {
	if (argc == 0) {
		return -1;
	}

	auto& container = *static_cast<std::vector<std::string>*>(data);

	if (!argv[0]) {
		container.push_back("NULL");
	}
	else {
		container.push_back(argv[0]);
	}

	return 0;
}

void StudentDB(sqlite3* DB) {

	char* messageError;
	string exit;
	string Q1;

	string student = "CREATE TABLE STUDENT("
		"ID INTEGER PRIMARY KEY, "
		"FIRST_NAME TEXT NOT NULL, "
		"LAST_NAME TEXT NOT NULL, "
		"GPA REAL NOT NULL); ";

	exit = sqlite3_exec(DB, student.c_str(), NULL, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES (10001, 'Isaac', 'Newton', 4.0)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES (10002, 'Marie', 'Curie', 3.9)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES (10003, 'Nikola', 'Tesla', 3.8)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES (10004, 'Thomas', 'Edison', 3.7)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES (10005, 'Jon', 'Neumann', 3.6)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES (10006, 'Grace', 'Hopper', 3.5)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES (10007, 'Mae', 'Jemison', 3.4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES (10008, 'Mark', 'Dean', 3.3)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES (10009, 'Michael', 'Faraday', 3.2)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES (10010, 'Ada', 'Lovelace', 4.0)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);
}

void InstructorDB(sqlite3* DB) {
	char* messageError;
	string exit;
	string Q1;

	string instructor = "CREATE TABLE INSTRUCTOR("
		"ID INTEGER PRIMARY KEY, "
		"FIRST_NAME TEXT NOT NULL, "
		"LAST_NAME TEXT NOT NULL, "
		"DEPARTMENT TEXT NOT NULL); ";

	exit = sqlite3_exec(DB, instructor.c_str(), NULL, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES (20001, 'Joseph', 'Fourier', 'BSME')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES (20002, 'Nelson', 'Patrick', 'BSCE')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES (20003, 'Galileo', 'Galilei', 'BSEE')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES (20004, 'Alan', 'Turing', 'BSCO')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES (20005, 'Daniel', 'Bernoulli', 'BSEE')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

}

void AdminDB(sqlite3* DB) {
	char* messageError;
	string exit;
	string Q1;

	string admin = "CREATE TABLE ADMIN("
		"ID INTEGER PRIMARY KEY, "
		"FIRST_NAME TEXT NOT NULL, "
		"LAST_NAME TEXT NOT NULL, "
		"OFFICE TEXT NOT NULL); ";

	exit = sqlite3_exec(DB, admin.c_str(), NULL, 0, &messageError);

	Q1 = "INSERT INTO ADMIN VALUES (30001, 'Margaret', 'Hamilton', 'DOBBS 302')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO ADMIN VALUES (30002, 'Vera', 'Rubin', 'BEATTY 501')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

}

void CourseDB(sqlite3* DB) {
	char* messageError;
	string exit;
	string Q1;

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

	exit = sqlite3_exec(DB, course.c_str(), NULL, 0, &messageError);

	Q1 = "INSERT INTO COURSE VALUES (13205, 'Network Theory I', 'BSEE', 'MW', 8, 9, 'F', 10, 12, 'Fall', 2021, 4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO COURSE VALUES (13778, 'Environmental Engineering', 'BSCE', 'TR', 8, 9, 'F', 10, 12, 'Fall', 2021, 4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO COURSE VALUES (14887, 'Signal and Systems', 'BSEE', 'TR', 12, 1, 'M', 10, 12, 'Fall', 2021, 4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO COURSE VALUES (32380, 'Electromagnetic Field Theory', 'BSME', 'MW', 9, 10, 'F', 5, 7,'Fall', 2021, 4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO COURSE VALUES (32401, 'Computer Architecture', 'BSCO', 'WF', 2, 3, 'F', 4, 6, 'Fall', 2021, 4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);
}


/*
std::vector<Course*> create_courselist(std::vector<std::string> container, sqlite3* DB) {
	const int CNum = 5;
	string Q1;
	string exit;
	std::vector<Course*> courselist;
	string tempS;
	int tempI;

	int CRN[CNum];
	string Title[CNum];
	string Department[CNum];
	string Time[CNum];
	string Days[CNum];
	string Semester[CNum];
	string Year[CNum];
	int Credit[CNum];

	Q1 = "SELECT * FROM COURSE";
	sqlite3_exec(DB, Q1.c_str(), callback, NULL, NULL);			// print user information

	Q1 = "SELECT CRN FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		stringstream T(container[i]);
		T >> tempI;
		CRN[i] = tempI;
	}

	Q1 = "SELECT TITLE FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Title[i] = container[CNum + i];
	}

	Q1 = "SELECT DEPTARPMENT FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Department[i] = container[2 * CNum + i];
	}

	Q1 = "SELECT TIME FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Time[i] = container[3 * CNum + i];
	}

	Q1 = "SELECT DAYS FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Days[i] = container[4 * CNum + i];
	}

	Q1 = "SELECT SEMESTER FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Semester[i] = container[5 * CNum + i];
	}

	Q1 = "SELECT YEAR FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Year[i] = container[6 * CNum + i];
	}

	Q1 = "SELECT CREDITS FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		stringstream T(container[7 * CNum + i]);
		T >> tempI;
		Credit[i] = tempI;
	}

	return courselist;
}
*/
