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

void Student::addDropCourse()
{
	vector<Course*> Schedule;
	vector<Course*> mainCourseList;
	// Function for putting values in vector
	char choice;
	int CRN_C;

	cout << "Would you like to add or drop a course?: " << endl
		<< "a - add" << endl
		<< "b - drop" << endl;
	cin >> choice; 
	if (choice == 'a') {
		cout << "Enter CRN of class you would like to add: "; cin >> CRN_C;
		for (int i = 0; i < mainCourseList.size(); i++) {
			Course* Temp;
			Temp = mainCourseList[i];
			if (Temp[i].getCode() == CRN_C) {
				Schedule.push_back(Temp);
			}
		}
	}
	else if (choice == 'b'){
		cout << "Enter CRN of class you would like to remove: "; cin >> CRN_C;
		for (int i = 0; i < Schedule.size(); i++) {
			Course* Temp;
			Temp = Schedule[i];
			if (Temp[i].getCode() == CRN_C) {
				Schedule.erase(std::next(Schedule.begin(), i)); 
			}
		}
	}

}

void Student::printSchedule() const
{
	cout << "Print schedule function called" << endl;
}

//SET & GET FUNCTIONS
void Student::setGPA(double gpa) { studentGPA = gpa; }
double Student::getGPA() const { return studentGPA; }

//DESTRUCTOR
Student::~Student()
{
	cout << "Destructor for Student called" << endl;
}