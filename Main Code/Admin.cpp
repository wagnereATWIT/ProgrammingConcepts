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

void Admin::addRemoveCourse(sqlite3* DB)								// *** NEED FOR ASSIGNMENT 5 ***
{
	char* messageError;
	char choice;
	string CRN, Lec_S, Lec_E, Lab_S, Lab_E, Year, Credits;
	string Title, Dept, Lec, Lab, Sem;

	string courseID;

	cout << "Would you like to add or drop a course?: " << endl
		<< "a - add" << endl
		<< "b - drop" << endl;
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
			"VALUES(" + CRN + ",'" + Title + "','" + Dept + "','" + Lec + "', " + Lec_S + "," + Lec_E + ",'" + Lab + "'," + Lab_S + "," + Lab_E + ",'" + Sem + "'," + Year + "," + Credits + "); ";
		int exit = sqlite3_exec(DB, Q1.c_str(), callback, NULL, &messageError);

		string printS1 = "SELECT * FROM COURSE WHERE CRN = ";
		string printS = printS1 + CRN;
		sqlite3_exec(DB, printS.c_str(), callback, NULL, &messageError);

		if (exit != SQLITE_OK)
		{
			std::cerr << "Error inserting course" << std::endl;
			sqlite3_free(messageError);
		}
		else {
			std::cout << "Insert successful!" << std::endl;
		}


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
			std::cout << "Records removed successfully!" << std::endl;
		}
	}
}

void Admin::addRemoveUser()
{
	cout << "Add/Remove user function called" << endl;
}

void Admin::addRemoveStudCourse()
{
	cout << "Add/Remove student from course function called" << endl;
}

void Admin::searchRoster()
{
	cout << "Search class list function called" << endl;
}

void Admin::printRoster() const
{
	cout << "Print class list function called" << endl;
}

void Admin::printCourse() const
{
	cout << "Print course function called" << endl;
}

//SET & GET FUNCTIONS
void Admin::setOffice(string office) { adOffice = office; }
string Admin::getOffice() const { return adOffice; }

//DESTRUCTOR
Admin::~Admin()
{
	cout << "Destructor for Admin called" << endl;
}
