#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : studentId(0), numCourses(0) {
    for (int i = 0; i < MAX_COURSES; i++)
        courses[i] = 0;
}

Student::Student(const string& name, const Date& dob,
                 int id, const Date& enrollDate)
    : Person(name, dob), studentId(id), enrollmentDate(enrollDate), numCourses(0) {
    for (int i = 0; i < MAX_COURSES; i++)
        courses[i] = 0;
}

Student::~Student() {
    cout << "Student object destroyed: " << getName()
         << " (ID: " << studentId << ")" << endl;
    // Note: we do NOT delete the course pointers here because Student
    // does not own the Course objects — CourseRegistration owns them.
    for (int i = 0; i < MAX_COURSES; i++)
        courses[i] = 0;
}

int  Student::getStudentId()      const { return studentId; }
Date Student::getEnrollmentDate() const { return enrollmentDate; }
int  Student::getNumCourses()     const { return numCourses; }
Course* Student::getCourse(int i) const {
    if (i >= 0 && i < MAX_COURSES) return courses[i];
    return 0;
}

void Student::setStudentId(int id)          { studentId = id; }
void Student::setEnrollmentDate(const Date& d) { enrollmentDate = d; }

bool Student::addCourse(Course* course) {
    if (numCourses >= MAX_COURSES) {
        cout << "  [Student] " << getName()
             << " is already enrolled in the maximum number of courses." << endl;
        return false;
    }
    // Check for duplicate
    for (int i = 0; i < MAX_COURSES; i++) {
        if (courses[i] != 0 &&
            courses[i]->getDepartmentName() == course->getDepartmentName() &&
            courses[i]->getCourseNumber()   == course->getCourseNumber()) {
            cout << "  [Student] " << getName()
                 << " is already enrolled in "
                 << course->getDepartmentName() << " "
                 << course->getCourseNumber() << "." << endl;
            return false;
        }
    }
    // Find first empty slot
    for (int i = 0; i < MAX_COURSES; i++) {
        if (courses[i] == 0) {
            courses[i] = course;
            numCourses++;
            return true;
        }
    }
    return false;
}

bool Student::removeCourse(const string& dept, int courseNum) {
    for (int i = 0; i < MAX_COURSES; i++) {
        if (courses[i] != 0 &&
            courses[i]->getDepartmentName() == dept &&
            courses[i]->getCourseNumber()   == courseNum) {
            courses[i] = 0;
            numCourses--;
            return true;
        }
    }
    cout << "  [Student] Course " << dept << " " << courseNum
         << " not found in " << getName() << "'s schedule." << endl;
    return false;
}

void Student::print() const {
    cout << "--- Student ---" << endl;
    Person::print();
    cout << endl;
    cout << "  Student ID: " << studentId << endl;
    cout << "  Enrollment Date: ";
    enrollmentDate.print();
    cout << endl;
    cout << "  Courses enrolled (" << numCourses << "):" << endl;
    for (int i = 0; i < MAX_COURSES; i++) {
        if (courses[i] != 0) {
            cout << "    ";
            courses[i]->print();
            cout << endl;
        }
    }
}
