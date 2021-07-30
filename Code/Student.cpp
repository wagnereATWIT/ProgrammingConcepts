//Student.cpp

#include "Student.h"
using namespace std;

//CONSTRUCTOR
Student::Student(string fName, string lName, int ID, double gpa)
	:User{ fName, lName, ID }
{
	this->studentGPA = gpa;
}

//FUNCTIONS
string Student::toString() const
{
	ostringstream output;
	output << "User Credentials" << endl
		<< "First name: " << getFirstName() << endl
		<< "Last Name: " << getLastName() << endl
		<< "ID Number: " << getID() << endl
		<< "GPA: " << getGPA() << endl;
	return output.str();
}

std::vector<Course> Student::addDropCourse(sqlite3* DB, vector<Course> Schedule)
{
	std::vector<std::string> container;
	vector<Course> mainCourseList = create_courselist(container, DB);
	// Function for putting values in vector
	char choice;
	int CRN_C = 0;

	cout << "Would you like to add or drop a course?: " << endl
		<< "a - add" << endl
		<< "b - drop" << endl;
	cin >> choice; 
	if (choice == 'a') {
		cout << "Enter CRN of class you would like to add: "; cin >> CRN_C;
		for (int i = 0; i < mainCourseList.size(); i++) {
			if (mainCourseList[i].getCode() == CRN_C) {
				Schedule.push_back(mainCourseList[i]);
				cout << mainCourseList[i].getCourse() << " added to schedule" << endl;
			}
		}
	}
	else if (choice == 'b'){
		cout << "Enter CRN of class you would like to remove: "; cin >> CRN_C;
		for (int i = 0; i < Schedule.size(); i++) {
			if (Schedule[i].getCode() == CRN_C) {
				cout << Schedule[i].getCourse() << " removed from schedule" << endl;
				Schedule.erase(Schedule.begin() + i);  
			}
		}
	}

	return Schedule; 
}

void Student::printSchedule(std::vector<Course> Schedule) const
{
	cout << "Print schedule function called" << endl;
	cout << "--------------------------------" << endl;
	for (int i = 0; i < Schedule.size(); i++) {
		cout << Schedule[i];
		cout << "--------------------------------" << endl;
	}
}

//SET & GET FUNCTIONS
void Student::setGPA(double gpa) { studentGPA = gpa; }
double Student::getGPA() const { return studentGPA; }

//DESTRUCTOR
Student::~Student()
{}