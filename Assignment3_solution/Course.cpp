#include "Course.h"
#include <iostream>
using namespace std;

Course::Course() : departmentName(""), courseNumber(0), courseName("") {}

Course::Course(const string& dept, int number, const string& name)
    : departmentName(dept), courseNumber(number), courseName(name) {}

Course::~Course() {
    cout << "Course object destroyed: " << departmentName << " " << courseNumber << endl;
}

string Course::getDepartmentName() const { return departmentName; }
int    Course::getCourseNumber()   const { return courseNumber; }
string Course::getCourseName()     const { return courseName; }

void Course::setDepartmentName(const string& dept) { departmentName = dept; }
void Course::setCourseNumber(int number)            { courseNumber = number; }
void Course::setCourseName(const string& name)      { courseName = name; }

void Course::print() const {
    cout << "Course: " << departmentName << " " << courseNumber
         << " - " << courseName;
}
