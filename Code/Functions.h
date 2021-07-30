#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include <vector>
#include <string>
#include <sstream>

#include "Course.h"

// Call back functions
int callback(void*, int, char**, char**);
int callback_store(void*, int, char**, char**);

void StudentDB(sqlite3*);
void InstructorDB(sqlite3*);
void AdminDB(sqlite3*);
void CourseDB(sqlite3*);

void ResetDB(sqlite3*);

// Create vector with all courses in it
std::vector<Course> create_courselist(std::vector<std::string>, sqlite3*);

#endif