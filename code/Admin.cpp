//Admin.cpp

#include "Admin.h"
using namespace std;

//CONSTRUCTOR
Admin::Admin(string fName, string lName, int ID, string office)
	:User{ fName, lName, ID }
{
	this->adOffice = office;
}

//FUNCTIONS
string Admin::toString() const
{
	ostringstream output;
	output << "User Credentials" << endl
		<< "First name: " << getFirstName() << endl
		<< "Last Name: " << getLastName() << endl
		<< "ID Number: " << getID() << endl
		<< "Office: " << getOffice() << endl;
	return output.str();
}

void Admin::addRemoveCourse(sqlite3* DB)
{
	char* messageError;
	char choice;
	string CRN, Lec_S, Lec_E, Lab_S, Lab_E, Year, Credits;
	string Title, Dept, Lec, Lab, Sem;

	string courseID;

	cout << "Would you like to add or drop a course?: " << endl
		<< "a - add" << endl
		<< "b - remove" << endl;
	cin >> choice;
	if (choice == 'a') {
		cout << endl << "Enter the following info for the class you would like to add: ";
		cout << endl << "CRN: "; cin >> CRN;
		cout << endl << "Title: "; cin.ignore();  getline(cin, Title);
		cout << endl << "Department (four letter): "; cin >> Dept;
		cout << endl << "Lecture days (single letter): "; cin >> Lec;
		cout << endl << "Lecture start time: "; cin >> Lec_S;
		cout << endl << "Lecture end time: "; cin >> Lec_E;
		cout << endl << "Lab days (single letter): "; cin >> Lab;
		cout << endl << "Lab start time: "; cin >> Lab_S;
		cout << endl << "Lab end time: "; cin >> Lab_E;
		cout << endl << "Semester: "; cin >> Sem;
		cout << endl << "Year: "; cin >> Year;
		cout << endl << "Credits: "; cin >> Credits;

		//Create course database entry
		string Q1 = "INSERT INTO COURSE (CRN, TITLE, DEPARTMENT, LECTURE_DAYS, LECTURE_START, LECTURE_END, LAB_DAYS, LAB_START, LAB_END, SEMESTER, YEAR, CREDITS) "\
			"VALUES(" + CRN +  ",'" + Title + "','" + Dept + "','" + Lec + "', " + Lec_S + "," + Lec_E + ",'" + Lab + "'," + Lab_S + "," + Lab_E + ",'" + Sem + "'," + Year + "," + Credits + "); ";
		int exit = sqlite3_exec(DB, Q1.c_str(), callback, NULL, &messageError);

		string printS1 = "SELECT * FROM COURSE WHERE CRN = ";
		string printS = printS1 + CRN;
		sqlite3_exec(DB, printS.c_str(), callback, NULL, &messageError);

		if (exit != SQLITE_OK)
		{
			std::cerr << "Error" << std::endl;
			sqlite3_free(messageError);
		}
		else {
			std::cout << "Successful" << std::endl;
		}

		Q1 = "INSERT INTO SCHEDULE (CRN, INSTRUCTOR, STUDENT1, STUDENT2, STUDENT3, STUDENT4) "\
			"VALUES (" + CRN + ", 0, 0, 0, 0);";	
		exit = sqlite3_exec(DB, Q1.c_str(), callback, NULL, &messageError);
	}
	else if (choice == 'b') {
		cout << "Enter CRN of class you would like to remove: "; cin >> courseID;
		string deleteC1 = "DELETE FROM COURSE WHERE CRN = ";
		string deleteC = deleteC1 + courseID;
		int exit = sqlite3_exec(DB, deleteC.c_str(), callback, NULL, &messageError);

		if (exit != SQLITE_OK)
		{
			std::cerr << "Error Removal" << std::endl;
			sqlite3_free(messageError);
		}
		else {
			std::cout << "Records removed Successfully!" << std::endl;
		}

		string Q1 = "DELETE FROM SCHEDULE WHERE CRN = ";
		string Q2 = Q1 + courseID; 
		exit = sqlite3_exec(DB, Q2.c_str(), callback, NULL, &messageError);
	}
}

void Admin::addRemoveUser(sqlite3* DB) {
	char choice;
	char U_Type;
	string U_ID; 
	string Q1;
	string Q2; 
	int exit;

	string First_Name;
	string Last_Name;
	string Password;

	string GPA;
	string Department;
	string Office;

	std::cout << "Add/Remove user function called" << std::endl;
	std::cout << "Would you like to add or remove a user?" << std::endl;
	std::cout << "a - add user" << std::endl << "b - remove user" << std::endl;
	std::cin >> choice;

	switch (choice) {
	case 'a':
		std::cout << "What kind of user would you like to add?" << std::endl;
		std::cout << "a - Student" << std::endl << "b - Instructor" << std::endl << "c - Admin" << std::endl;
		std::cin >> U_Type;

		std::cout << "Enter ID #: "; std::cin >> U_ID;
		std::cout << "Enter First Name: "; std::cin >> First_Name;
		std::cout << "Enter Last Name: "; std::cin >> Last_Name;
		std::cout << "Enter Password: "; std::cin >> Password;

		switch (U_Type) {
		case 'a':
			std::cout << "Enter GPA: "; std::cin >> GPA;

			Q1 = "INSERT INTO STUDENT (ID, FIRST_NAME, LAST_NAME, GPA, PASSWORD) "\
				"VALUES(" + U_ID + ",'" + First_Name + "','" + Last_Name + "'," + GPA + ", '" + Password + "'); ";
			exit = sqlite3_exec(DB, Q1.c_str(), callback, NULL, NULL);

			std::cout << "-------------------------------------------------" << std::endl;
			Q1 = "SELECT * FROM STUDENT WHERE ID = ";
			Q2 = Q1 + U_ID;
			exit = sqlite3_exec(DB, Q2.c_str(), callback, NULL, NULL);

			break;
		case 'b':
			std::cout << "Enter Department: "; std::cin >> Department;

			Q1 = "INSERT INTO INSTRUCTOR (ID, FIRST_NAME, LAST_NAME, DEPARTMENT, PASSWORD) "\
				"VALUES(" + U_ID + ",'" + First_Name + "','" + Last_Name + "','" + Department + "', '" + Password + "'); ";
			exit = sqlite3_exec(DB, Q1.c_str(), callback, NULL, NULL);
			break;
		case 'c':
			std::cout << "Enter Office Location: "; std::cin.ignore(); getline(cin, Office);

			Q1 = "INSERT INTO ADMIN (ID, FIRST_NAME, LAST_NAME, OFFICE, PASSWORD) "\
				"VALUES(" + U_ID + ",'" + First_Name + "','" + Last_Name + "','" + Office + "', '" + Password + "'); ";
			exit = sqlite3_exec(DB, Q1.c_str(), callback, NULL, NULL);
			break;
		}
		break;
	case 'b':
		std::cout << "Enter the ID of the user you would like to remove: ";
		std::cin >> U_ID;

		Q1 = "DELETE FROM STUDENT WHERE ID = ";
		Q2 = Q1 + U_ID;
		exit = sqlite3_exec(DB, Q2.c_str(), callback, NULL, NULL);

		Q1 = "DELETE FROM INSTRUCTOR WHERE ID = ";
		Q2 = Q1 + U_ID;
		exit = sqlite3_exec(DB, Q2.c_str(), callback, NULL, NULL);

		Q1 = "DELETE FROM ADMIN WHERE ID = ";
		Q2 = Q1 + U_ID;
		exit = sqlite3_exec(DB, Q2.c_str(), callback, NULL, NULL);

		break;
	}
}

void Admin::printUsers(sqlite3* DB) {
	string Q1;
	string exit;

	Q1 = "SELECT * FROM STUDENT;";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, NULL, NULL);

	Q1 = "SELECT * FROM INSTRUCTOR;";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, NULL, NULL);

	Q1 = "SELECT * FROM ADMIN;";
	exit = sqlite3_exec(DB, Q1.c_str(), callback, NULL, NULL);
}

void Admin::LinkUser(sqlite3* DB) {
	string Q1;
	string Q2;
	int exit; 
	char* messageError;
	bool cont = true;

	string students[3] = { "STUDENT1", "STUDENT2", "STUDENT3" }; 

	vector<string> container;

	char choice;
	string CRN;
	string ID;

	cout << "Add/Remove user from course: " << endl;
	std::cout << "a - link user" << std::endl 
		<< "b - unlink user" << std::endl 
		<< "c - print all courses' instructors and students" << endl;
	std::cin >> choice;

	switch (choice) {
	case 'a':
		cout << "Link User" << endl;
		cout << "Enter ID of user you would like to link: ";
		cin >> ID;
		cout << "Enter CRN of course you would like to link user to: ";
		cin >> CRN;
		if (ID[0] == '1') {
			for (int i = 0; i < 3; i++) {
				Q1 = string("UPDATE SCHEDULE SET ") + students[i] + string(" = ") + ID + string(" WHERE CRN = ") + CRN + string(" AND ") + students[i] + string(" = 0");
				exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, &messageError);
			}
		}
		if (ID[0] == '2') {
			Q1 = string("UPDATE SCHEDULE SET INSTRUCTOR = ") + ID + string(" WHERE CRN = ") + CRN;
			exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, NULL);
		}
		break;
	case 'b':
		cout << "Unlink User" << endl;
		cout << "Enter ID of user you would like to unlink: ";
		cin >> ID;
		cout << "Enter CRN of course you would like to unlink user to: ";
		cin >> CRN;

		if (ID[0] == '1') {
			for (int i = 0; i < 3; i++) {
				Q1 = string("UPDATE SCHEDULE SET ") + students[i] + string(" = 0 WHERE CRN = ") + CRN + string(" AND ") + students[i] + string(" = ") + ID;
				exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, NULL);
			}
		}
		if (ID[0] == '2') {
			Q1 = string("UPDATE SCHEDULE SET INSTRUCTOR = 0") + string(" WHERE CRN = ") + CRN;
			exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, NULL);
		}

		break;
	case 'c':
		Q1 = "SELECT * FROM SCHEDULE";
		exit = sqlite3_exec(DB, Q1.c_str(), callback, 0, NULL);
		break;
	}
}

//SET & GET FUNCTIONS
void Admin::setOffice(string office) { adOffice = office; }
string Admin::getOffice() const { return adOffice; }

//DESTRUCTOR
Admin::~Admin()
{}