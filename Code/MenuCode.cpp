#include<iostream>
#include<string>

using namespace std;

void login();

void menu_admin();
void menu_instructor();
void menu_student();

int main() {
	string User_type;
	cout << "-----Log in-----" << endl;
	login();

	// Figure out if the user is an admin, instructor, or student. This will change which menu is displayed
	// Id is five # long

	if (User_type == "Admin") {
		// if user is an admin call:
		menu_admin();
	}
	else if (User_type == "Instructor") {
		// if user is an instructor call:
		menu_instructor();
	}
	else if (User_type == "Student") {
		// if user is a student call:
		menu_student();
	}
	else {
		cout << "Error: Cannot determine user type" << endl;
	}
	


	return 0;
}

void login() {
	string UN;
	string PW;
	bool looper = 1;

	do {
		cout << "User name: "; cin >> UN;
		cout << "Password: "; cin >> PW;
	} while (looper == 0);
	
	// find user name in the database
	// if user name is not in database return log in error
	// if password is incorrect return log in error
	// else continue
}

void menu_admin() {
	int loop = 0;
	char choice;
	while (loop == 0) {
		cout << "------Menu------" << endl;
		cout << "a - Course Search " << endl
			<< "b - Advanced Search" << endl
			<< "c - Add/Remove Courses (system)" << endl
			<< "d - Log-out" << endl;
		cin >> choice;
		switch (choice) {
			case 'a':
				// Call Course Search Function
				break;
			case 'b':
				// Call Advanced Search Function
				break;
			case 'c':
				// Call Add/Remove Courses (system)
				break;
			case 'd':
				cout << "Logging out..." << endl;
				loop = 1;
		}
	}
}

void menu_instructor() {
	int loop = 0;
	char choice;
	while (loop == 0) {
		cout << "------Menu------" << endl;
		cout << "a - Course Search " << endl
			<< "b - Advanced Search" << endl
			<< "c - Course Roster" << endl
			<< "d - Log-out" << endl;
		cin >> choice;
		switch (choice) {
		case 'a':
			// Call Course Search Function
			break;
		case 'b':
			// Call Advanced Search Function
			break;
		case 'c':
			// Call Course Roster
			break;
		case 'd':
			cout << "Logging out..." << endl;
			loop = 1;
		}
	}
}

void menu_student() {
	int loop = 0;
	char choice;
	while (loop == 0) {
		cout << "------Menu------" << endl;
		cout << "a - Course Search " << endl
			<< "b - Advanced Search" << endl
			<< "c - Add/Remove Courses (schedule)" << endl
			<< "d - Log-out" << endl;
		cin >> choice;
		switch (choice) {
		case 'a':
			// Call Course Search Function
			break;
		case 'b':
			// Call Advanced Search Function
			break;
		case 'c':
			// Call Add/Remove Courses (schedule)
			break;
		case 'd':
			cout << "Logging out..." << endl;
			loop = 1;
		}
	}
}
