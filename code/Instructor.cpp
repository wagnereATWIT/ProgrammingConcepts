//Instructor.cpp
#include "Instructor.h"
using namespace std;

//CONSTRUCTOR
Instructor::Instructor(string fName, string lName, int ID, string school)
	:User{ fName, lName, ID }
{
	this->schoolType = school;
}

//FUNCTIONS
string Instructor::toString() const 
{
	ostringstream output;
	output << "User Credentials" << endl
		<< "First name: " << getFirstName() << endl
		<< "Last Name: " << getLastName() << endl
		<< "ID Number: " << getID() << endl
		<< "School: " << getSchool() << endl;
	return output.str();
}

void Instructor::printRoster(sqlite3* DB, std::vector<Course> Schedule)
{
	string department;
	cout << endl << "Enter your four-letter department name: ";
	cin >> department;
	//Flag professors that can teach the courses
	string flagProf_1 = "SELECT COURSE.TITLE, COURSE.LECTURE_DAYS, COURSE.LECTURE_START, COURSE.LECTURE_END, COURSE.LAB_DAYS, COURSE.LAB_START, COURSE.LAB_END FROM COURSE WHERE COURSE.DEPARTMENT = ";
	string flagProf = flagProf_1 + '"' + department + '"';
	cout << endl << "Roster: " << endl;
	sqlite3_exec(DB, flagProf.c_str(), callback, NULL, NULL);

	string Q1;
	string Q2;
	vector<string> container;

	for (int i = 0; i < Schedule.size(); i++) {
		string CRN = to_string(Schedule[i].getCode());
		cout << "COURSE: " << Schedule[i].getCourse() << endl;
		cout << "---------------------------------" << endl;
		Q1 = "SELECT STUDENT1 FROM SCHEDULE WHERE CRN = ";
		Q2 = Q1 + CRN; 
		sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);

		Q1 = "SELECT STUDENT2 FROM SCHEDULE WHERE CRN = ";
		Q2 = Q1 + CRN;
		sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);

		Q1 = "SELECT STUDENT3 FROM SCHEDULE WHERE CRN = ";
		Q2 = Q1 + CRN;
		sqlite3_exec(DB, Q2.c_str(), callback_store, &container, NULL);

		for (int j = 0; j < container.size(); j++) {
			if (container[j] != "0") {
				Q1 = "SELECT STUDENT.FIRST_NAME, STUDENT.LAST_NAME FROM STUDENT WHERE ID =";
				Q2 = Q1 + container[j];
				sqlite3_exec(DB, Q2.c_str(), callback, NULL, NULL);
				cout << "---------------------------------" << endl;
			}
		}
	}
}

void Instructor::printSchedule(std::vector<Course> Schedule) const
{
	cout << "--------------------------------" << endl;
	for (int i = 0; i < Schedule.size(); i++) {
		cout << Schedule[i];
		cout << "--------------------------------" << endl;
	}
}

//SET & GET FUNCTIONS
void Instructor::setSchool(string school) { schoolType = school; }
string Instructor::getSchool() const { return schoolType; }

//DESTRUCTOR
Instructor::~Instructor()
{}