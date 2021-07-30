#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include <sstream> 

#include "User.h"
#include "Admin.h"
#include "Student.h"
#include "Instructor.h"

#include "Course.h"
#include "Functions.h"

std::string login(sqlite3*, std::vector<std::string>); 

void menu_instructor(Instructor& I, sqlite3*);
void menu_admin(Admin& A, sqlite3*);
void menu_student(Student& S, sqlite3*);

Student create_student(sqlite3*, std::vector<std::string>, std::string);
Instructor create_instructor(sqlite3*, std::vector<std::string>, std::string);
Admin create_admin(sqlite3*, std::vector<std::string>, std::string);

bool password_check(sqlite3*, std::string, std::string);

#endif
