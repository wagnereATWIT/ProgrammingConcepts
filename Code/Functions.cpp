
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

void ResetDB(sqlite3* DB) {
	string Q1;
	string exit;
	char* messageError;

	Q1 = "DROP TABLE ADMIN";
	exit = sqlite3_exec(DB, Q1.c_str(), NULL, 0, &messageError);

	Q1 = "DROP TABLE COURSE";
	exit = sqlite3_exec(DB, Q1.c_str(), NULL, 0, &messageError);

	Q1 = "DROP TABLE INSTRUCTOR";
	exit = sqlite3_exec(DB, Q1.c_str(), NULL, 0, &messageError);

	Q1 = "DROP TABLE STUDENT";
	exit = sqlite3_exec(DB, Q1.c_str(), NULL, 0, &messageError);

}

void StudentDB(sqlite3* DB) {

	char* messageError;
	string exit;
	string Q1;

	string student = "CREATE TABLE STUDENT("
		"ID INTEGER PRIMARY KEY, "
		"FIRST_NAME TEXT NOT NULL, "
		"LAST_NAME TEXT NOT NULL, "
		"GPA REAL NOT NULL, "
		"PASSWORD TEXT); ";

	exit = sqlite3_exec(DB, student.c_str(), NULL, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES ('10001','Isaac','Newton','4.0','computer')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES ('10002','Marie','Curie','3.9','131313')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES ('10003','Nikola','Tesla','3.8','freedom')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES ('10004','Thomas','Edison','3.7','matrix')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES ('10005','Jon','Neumann','3.6','access')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES ('10006','Grace','Hopper','3.5','open')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES ('10007','Mae','Jemison','3.4','help')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES ('10008','Mark','Dean','3.3','unknown')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES ('10009','Michael','Faraday','3.2','pokemon')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO STUDENT VALUES ('10010','Ada','Lovelace','4.0','zing')";
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
		"DEPARTMENT TEXT NOT NULL, "
		"PASSWORD TEXT); ";

	exit = sqlite3_exec(DB, instructor.c_str(), NULL, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES ('20001','Joseph','Fourier','BSME','qwerty')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES ('20002','Samantha','Jackson','BSME','12345')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES ('20003','Dude','Junior','BSCE','password')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES ('20004','Nelson','Patrick','BSCE','winter20')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES ('20005','Galileo','Galilei','BSEE','asdf')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES ('20006','Daniel','Bernoulli','BSEE','ricecakes')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES ('20007','Alan','Turing','BSCO','icewater')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES ('20008','Peter','Man','BSCO','daniel')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES ('20009','Ray','Bolder','BSCS','pass')";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO INSTRUCTOR VALUES ('20010','Jennifer','Swanson','BSCS','aaaaa')";
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
		"OFFICE TEXT NOT NULL, "
		"PASSWORD TEXT); ";

	exit = sqlite3_exec(DB, admin.c_str(), NULL, 0, &messageError);

	Q1 = "INSERT INTO ADMIN VALUES ('30001','Margaret','Hamilton','DOBBS 302','password1')";
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

	// BSEE COURSES ------------------------------------------------------------------------------------
	Q1 = "INSERT INTO COURSE VALUES (13205,'Network Theory I','BSEE','MW',8,9,'F',10,12,'Fall',2021,4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO COURSE VALUES (14887,'Signal and Systems','BSEE','TR',12,1,'M',10,12,'Fall',2021,4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	// BSCE COURSES ------------------------------------------------------------------------------------
	Q1 = "INSERT INTO COURSE VALUES (13778,'Environmental Engineering','BSCE','TR',8,9,'F',10,12,'Fall',2021,4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO COURSE VALUES (14349,'Fluid Mechanics','BSCE','MF',8,9,'W',10,12,'Fall',2021,4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	// BSCO COURSES---------------------------------------------------------------------------------------
	Q1 = "INSERT INTO COURSE VALUES (32401,'Computer Architecture','BSCO','WF',2,3,'F',4,6,'Fall',2021,4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO COURSE VALUES (14882,'Computer Networks','BSCO','TR',1,2,'F',8,10,'Fall',2021,4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	// BSME COURSES ---------------------------------------------------------------------------------------
	Q1 = "INSERT INTO COURSE VALUES (32380,'Electromagnetic Field Theory','BSME','MW',9,10,'F',5,7,'Fall',2021,4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO COURSE VALUES (14956,'HVAC Systems','BSME','TR',5,6,'W',8,10,'Fall',2021,4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	// BSCS COURSES ----------------------------------------------------------------------------------------
	Q1 = "INSERT INTO COURSE VALUES (14420,'Software Engineering','BSCS','MR',3,5,'W',3,5,'Fall',2021,4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

	Q1 = "INSERT INTO COURSE VALUES (14801,'Algorithms','BSCS','MW',11,12,'F',10,12,'Fall',2021,4)";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);

}

std::vector<Course> create_courselist(std::vector<std::string> container, sqlite3* DB) {
	const int CNum = 10;
	string Q1;
	string exit;

	std::vector<Course> courselist;
	std::string::size_type sz;

	int CRN[CNum];
	string Title[CNum];
	string Department[CNum];

	string Lecture_Days[CNum];
	int Lecture_Start[CNum];
	int Lecture_End[CNum];

	string Lab_Days[CNum];
	int Lab_Start[CNum];
	int Lab_End[CNum];

	string Semester[CNum];
	int Year[CNum];
	int Credit[CNum];

	Q1 = "SELECT CRN FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		CRN[i] = std::stoi(container[i], &sz);
	}

	container.clear(); 
	Q1 = "SELECT TITLE FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Title[i] = container[i];
	}

	container.clear();
	Q1 = "SELECT DEPARTMENT FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Department[i] = container[i];
	}
	
	container.clear();
	Q1 = "SELECT LECTURE_DAYS FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Lecture_Days[i] = container[i];
	}

	container.clear();
	Q1 = "SELECT LECTURE_START FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Lecture_Start[i] = std::stoi(container[i], &sz);
	}

	container.clear();
	Q1 = "SELECT LECTURE_END FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Lecture_End[i] = std::stoi(container[i], &sz);
	}

	container.clear();
	Q1 = "SELECT LAB_DAYS FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Lab_Days[i] = container[i];
	}

	container.clear(); 
	Q1 = "SELECT LAB_START FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Lab_Start[i] = std::stoi(container[i], &sz);
	}

	container.clear();
	Q1 = "SELECT LAB_END FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Lab_End[i] = std::stoi(container[i], &sz);
	}

	container.clear();
	Q1 = "SELECT SEMESTER FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Semester[i] = container[i];
	}

	container.clear();
	Q1 = "SELECT YEAR FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Year[i] = std::stoi(container[i], &sz);
	}

	container.clear();
	Q1 = "SELECT CREDITS FROM COURSE ";
	exit = sqlite3_exec(DB, Q1.c_str(), callback_store, &container, NULL);
	for (int i = 0; i < CNum; i++) {
		Credit[i] = std::stoi(container[i], &sz);
	}
	
	for (int i = 0; i < CNum; i++) {
		Course TEMP(CRN[i], Title[i], Department[i], Lecture_Days[i], 
			Lecture_Start[i], Lecture_End[i], Lab_Days[i], Lab_Start[i], 
			Lab_End[i], Semester[i], Year[i], Credit[i]);

		courselist.push_back(TEMP);
	}

	return courselist;
}
