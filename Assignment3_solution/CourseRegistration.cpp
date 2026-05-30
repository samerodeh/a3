#include "CourseRegistration.h"
#include <iostream>
using namespace std;

CourseRegistration::CourseRegistration()
    : Course(), maxSize(0), numEnrolled(0), studentIds(0) {}

CourseRegistration::CourseRegistration(const string& dept, int number,
                                       const string& name, int maxSize)
    : Course(dept, number, name), maxSize(maxSize), numEnrolled(0) {
    studentIds = new int[maxSize];
    for (int i = 0; i < maxSize; i++)
        studentIds[i] = 0;
}

CourseRegistration::~CourseRegistration() {
    cout << "CourseRegistration object destroyed: "
         << getDepartmentName() << " " << getCourseNumber() << endl;
    delete[] studentIds;
    studentIds = 0;
}

int CourseRegistration::getMaxSize()     const { return maxSize; }
int CourseRegistration::getNumEnrolled() const { return numEnrolled; }

void CourseRegistration::setMaxSize(int size) {
    // Resize the array
    int* newArr = new int[size];
    int  toCopy = (size < numEnrolled) ? size : numEnrolled;
    for (int i = 0; i < size; i++)
        newArr[i] = (i < toCopy) ? studentIds[i] : 0;
    delete[] studentIds;
    studentIds = newArr;
    maxSize    = size;
    if (numEnrolled > maxSize)
        numEnrolled = maxSize;
}

bool CourseRegistration::registerStudent(int studentId) {
    if (numEnrolled >= maxSize) {
        cout << "  [CourseRegistration] Course "
             << getDepartmentName() << " " << getCourseNumber()
             << " is full." << endl;
        return false;
    }
    if (isStudentEnrolled(studentId)) {
        cout << "  [CourseRegistration] Student " << studentId
             << " is already registered in "
             << getDepartmentName() << " " << getCourseNumber() << "." << endl;
        return false;
    }
    // Find the first empty slot (stored as 0)
    for (int i = 0; i < maxSize; i++) {
        if (studentIds[i] == 0) {
            studentIds[i] = studentId;
            numEnrolled++;
            return true;
        }
    }
    return false;
}

bool CourseRegistration::removeStudent(int studentId) {
    for (int i = 0; i < maxSize; i++) {
        if (studentIds[i] == studentId) {
            studentIds[i] = 0;
            numEnrolled--;
            return true;
        }
    }
    cout << "  [CourseRegistration] Student " << studentId
         << " not found in "
         << getDepartmentName() << " " << getCourseNumber() << "." << endl;
    return false;
}

bool CourseRegistration::isStudentEnrolled(int studentId) const {
    for (int i = 0; i < maxSize; i++) {
        if (studentIds[i] == studentId)
            return true;
    }
    return false;
}

void CourseRegistration::print() const {
    Course::print();
    cout << endl;
    cout << "  Max Enrollment: " << maxSize
         << ", Currently Enrolled: " << numEnrolled << endl;
    cout << "  Enrolled Student IDs: ";
    bool first = true;
    for (int i = 0; i < maxSize; i++) {
        if (studentIds[i] != 0) {
            if (!first) cout << ", ";
            cout << studentIds[i];
            first = false;
        }
    }
    if (first) cout << "(none)";
    cout << endl;
}
