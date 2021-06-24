#include "User.h"
#include "Student.h"
#include "Instructor.h"
#include "Admin.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	Student s1{ "Kaycee", "Salgueiro", 3737, 3.70 };
	cout << "Calling get first name: " << s1.getFirstName() << endl;
	cout << "Calling get last name: " << s1.getLastName() << endl;
	cout << "Calling get ID name: " << s1.getID() << endl;
	cout << "Calling get GPA: " << s1.getGPA() << endl << endl;
	s1.searchCourse();
	s1.addDropCourse();
	s1.printSchedule();

	Instructor i1{ "Marisha", "Rawlins", 4475, "School of Engineering" };
	cout << endl << "Calling get first name: " << i1.getFirstName() << endl;
	cout << "Calling get last name: " << i1.getLastName() << endl;
	cout << "Calling get ID name: " << i1.getID() << endl;
	cout <<"Calling get school: " << i1.getSchool() << endl << endl;
	i1.searchCourse();
	i1.printRoster();
	i1.printSchedule();
	
	Admin a1{ "Billie", "Eilish", 8888, "ANXCN 104" };
	cout << endl << "Calling get first name: " << a1.getFirstName() << endl;
	cout << "Calling get last name: " << a1.getLastName() << endl;
	cout << "Calling get ID name: " << a1.getID() << endl;
	cout << "Calling get office: " << a1.getOffice() << endl << endl;
	a1.addRemoveCourse();
	a1.addRemoveUser();
	a1.addRemoveStudCourse();
	a1.searchCourse();
	a1.searchRoster();
	a1.printRoster();
	a1.printCourse();

	User* newStudent = new Student{ "Ryan","Hawksley", 9696, 3.45 };
	string studentS = newStudent->toString();
	cout << endl << studentS << endl;

	User* newInstructor = new Instructor{ "Kai","Ren", 5432, "School of Design" };
	string instructorS = newInstructor->toString();
	cout << instructorS << endl;

	User* newAdmin = new Admin{ "Barrack","Obama", 1111, "WENTW 202" };
	string adminS = newAdmin->toString();
	cout << adminS << endl;
	

	return 0;
}