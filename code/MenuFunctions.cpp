#include "MenuFunctions.h"
using namespace std;

string login(sqlite3* DB, std::vector<std::string> container) {
	int exit;
	char* messageError;
	string Q1;
	string Q2;
	string UN;
	string PW;
	string temp;
	bool pass = false;

	while (pass == false) {
		cout << "Username (Id #): "; cin >> UN;
		cout << "Password: "; cin >> PW;

		Q1 = "SELECT * FROM STUDENT WHERE ID = ";
		Q2 = Q1 + UN;
		exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, &messageError);

		Q1 = "SELECT * FROM INSTRUCTOR WHERE ID = ";
		Q2 = Q1 + UN;
		exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, &messageError);

		Q1 = "SELECT * FROM ADMIN WHERE ID = ";
		Q2 = Q1 + UN;
		exit = sqlite3_exec(DB, Q2.c_str(), callback_store, &container, &messageError);

		temp = container[0];

		pass = password_check(DB, temp, PW);
	}

	return temp;
}

bool password_check(sqlite3* DB, string ID, string password) {
	std::vector<std::string> container;
	string Q1, Q2;
	string temp;
	bool check = false;
	if (ID[0] == '1') {
		Q1 = "SELECT PASSWORD FROM STUDENT WHERE ID = ";
		Q2 = Q1 + ID;
		sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);

		temp = container[0];
		if (temp == password) {
			check = true;
		}
		else {
			cout << "Incorrect password" << endl;
		}
	}
	else if (ID[0] == '2') {
		Q1 = "SELECT PASSWORD FROM INSTRUCTOR WHERE ID = ";
		Q2 = Q1 + ID;
		sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);

		temp = container[0];
		if (temp == password) {
			check = true;
		}
		else {
			cout << "Incorrect password" << endl;
		}
	}
	else if (ID[0] == '3') {
		Q1 = "SELECT PASSWORD FROM ADMIN WHERE ID = ";
		Q2 = Q1 + ID;
		sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);

		temp = container[0];
		if (temp == password) {
			check = true;
		}
		else {
			cout << "Incorrect password" << endl;
		}
	}

	return check;
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

Instructor create_instructor(sqlite3* DB, std::vector<std::string> container, string ID) {
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
			<< "u - Add/Remove User" << endl
			<< "l - Link/Unlink User to Course" << endl
			<< "p - Print User List" << endl
			<< "x - Log-out" << endl;
		cin >> choice;
		switch (choice) {
		case 's':
			// Call Course Search Function
			A.searchCourse(DB);
			break;
		case 'a':
			// Call Add/Remove Courses (system)
			A.addRemoveCourse(DB);
			break;
		case 'u':
			A.addRemoveUser(DB);
			break;
		case 'l':
			A.LinkUser(DB);
			break;
		case 'p':
			A.printUsers(DB);
			break;
		case 'x':
			cout << "Logging out..." << endl;
			loop = 1;
		}
	}
}

void menu_student(Student& S, sqlite3* DB) {
	int ID;
	ID = S.getID();
	vector<Course> Schedule;
	Schedule = setSchedule(DB, ID);

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
	int ID;
	ID = I.getID();
	vector<Course> Schedule;
	Schedule = setSchedule(DB, ID);

	int loop = 0;
	char choice;
	while (loop == 0) {
		cout << "------Menu------" << endl;
		cout << "s - Course Search " << endl
			<< "r - Course Roster" << endl
			<< "p - Print Schedule" << endl
			<< "x - Log-out" << endl;
		cin >> choice;
		switch (choice) {
		case 's':
			// Call Course Search Function
			I.searchCourse(DB);
			break;
		case 'r':
			// Call Course Roster
			I.printRoster(DB, Schedule); 
			break;
		case 'p':
			I.printSchedule(Schedule); 
			break;
		case 'x':
			cout << "Logging out..." << endl;
			Schedule.clear();
			loop = 1;
		}
	}
}

vector<Course> setSchedule(sqlite3* DB, int ID) {
	vector<Course> Schedule;
	Schedule.clear(); 
	vector<string> container;
	container.clear();

	string Q1;
	string Q2;
	int exit;

	string id = to_string(ID);
	string CRN;

	vector<Course> mainCourseList = create_courselist(container, DB);

	Q1 = "SELECT CRN FROM SCHEDULE WHERE INSTRUCTOR = ";
	Q2 = Q1 + id;
	sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);

	Q1 = "SELECT CRN FROM SCHEDULE WHERE STUDENT1 = ";
	Q2 = Q1 + id;
	sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);

	Q1 = "SELECT CRN FROM SCHEDULE WHERE STUDENT2 = ";
	Q2 = Q1 + id;
	sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);

	Q1 = "SELECT CRN FROM SCHEDULE WHERE STUDENT3 = ";
	Q2 = Q1 + id;
	sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);

	for (auto it = container.begin(); it != container.end(); ++it) {
		int C = stoi(*it);
		for (int i = 0; i < mainCourseList.size(); i++) {
			if (mainCourseList[i].getCode() == C) {
				Schedule.push_back(mainCourseList[i]);
			}
		}
	}

	return Schedule;
}