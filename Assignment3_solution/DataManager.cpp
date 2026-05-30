#include "DataManager.h"
#include <iostream>
using namespace std;

// ── Constructor / Destructor ──────────────────────────────────────────────────

DataManager::DataManager() : numStudents(0), numCourses(0) {
    for (int i = 0; i < MAX_STUDENTS;    i++) students[i]   = 0;
    for (int i = 0; i < MAX_REG_COURSES; i++) courseRegs[i] = 0;
}

DataManager::~DataManager() {
    // Delete all remaining student objects
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (students[i] != 0) {
            delete students[i];
            students[i] = 0;
        }
    }
    // Delete all remaining course registration objects
    for (int i = 0; i < MAX_REG_COURSES; i++) {
        if (courseRegs[i] != 0) {
            delete courseRegs[i];
            courseRegs[i] = 0;
        }
    }
    cout << "DataManager destroyed." << endl;
}

// ── Private helpers ───────────────────────────────────────────────────────────

int DataManager::findStudentIndex(int studentId) const {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (students[i] != 0 && students[i]->getStudentId() == studentId)
            return i;
    }
    return -1;
}

int DataManager::findCourseIndex(const string& dept, int courseNum) const {
    for (int i = 0; i < MAX_REG_COURSES; i++) {
        if (courseRegs[i] != 0 &&
            courseRegs[i]->getDepartmentName() == dept &&
            courseRegs[i]->getCourseNumber()   == courseNum)
            return i;
    }
    return -1;
}

// ── University enrollment ─────────────────────────────────────────────────────

bool DataManager::enrollStudent(Student* student) {
    if (numStudents >= MAX_STUDENTS) {
        cout << "[DataManager] University is at full capacity." << endl;
        return false;
    }
    if (findStudentIndex(student->getStudentId()) != -1) {
        cout << "[DataManager] Student ID " << student->getStudentId()
             << " is already enrolled at the university." << endl;
        return false;
    }
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (students[i] == 0) {
            students[i] = student;
            numStudents++;
            cout << "[DataManager] Student " << student->getName()
                 << " (ID: " << student->getStudentId()
                 << ") enrolled at the university." << endl;
            return true;
        }
    }
    return false;
}

bool DataManager::removeStudent(int studentId) {
    int idx = findStudentIndex(studentId);
    if (idx == -1) {
        cout << "[DataManager] Student ID " << studentId
             << " not found at the university." << endl;
        return false;
    }
    // Drop the student from every course they are in first
    for (int i = 0; i < MAX_REG_COURSES; i++) {
        if (courseRegs[i] != 0 && courseRegs[i]->isStudentEnrolled(studentId)) {
            courseRegs[i]->removeStudent(studentId);
        }
    }
    cout << "[DataManager] Removing student "
         << students[idx]->getName()
         << " (ID: " << studentId << ") from the university." << endl;
    delete students[idx];
    students[idx] = 0;
    numStudents--;
    return true;
}

// ── Course management ─────────────────────────────────────────────────────────

bool DataManager::addCourse(CourseRegistration* cr) {
    if (numCourses >= MAX_REG_COURSES) {
        cout << "[DataManager] Maximum number of courses reached." << endl;
        return false;
    }
    if (findCourseIndex(cr->getDepartmentName(), cr->getCourseNumber()) != -1) {
        cout << "[DataManager] Course "
             << cr->getDepartmentName() << " " << cr->getCourseNumber()
             << " already exists." << endl;
        return false;
    }
    for (int i = 0; i < MAX_REG_COURSES; i++) {
        if (courseRegs[i] == 0) {
            courseRegs[i] = cr;
            numCourses++;
            cout << "[DataManager] Course "
                 << cr->getDepartmentName() << " " << cr->getCourseNumber()
                 << " - " << cr->getCourseName() << " added." << endl;
            return true;
        }
    }
    return false;
}

bool DataManager::removeCourse(const string& dept, int courseNum) {
    int idx = findCourseIndex(dept, courseNum);
    if (idx == -1) {
        cout << "[DataManager] Course " << dept << " " << courseNum
             << " not found." << endl;
        return false;
    }
    // Remove the course pointer from every student enrolled in it
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (students[i] != 0) {
            students[i]->removeCourse(dept, courseNum);
        }
    }
    cout << "[DataManager] Removing course "
         << dept << " " << courseNum << "." << endl;
    delete courseRegs[idx];
    courseRegs[idx] = 0;
    numCourses--;
    return true;
}

// ── Student-course operations ─────────────────────────────────────────────────

bool DataManager::registerStudentToCourse(int studentId,
                                          const string& dept, int courseNum) {
    int sIdx = findStudentIndex(studentId);
    if (sIdx == -1) {
        cout << "[DataManager] Student ID " << studentId
             << " not found." << endl;
        return false;
    }
    int cIdx = findCourseIndex(dept, courseNum);
    if (cIdx == -1) {
        cout << "[DataManager] Course " << dept << " " << courseNum
             << " not found." << endl;
        return false;
    }

    // Register in CourseRegistration (checks capacity & duplicates)
    if (!courseRegs[cIdx]->registerStudent(studentId))
        return false;

    // Add course pointer to Student (checks max courses & duplicates)
    if (!students[sIdx]->addCourse(courseRegs[cIdx])) {
        // Roll back the registration
        courseRegs[cIdx]->removeStudent(studentId);
        return false;
    }

    cout << "[DataManager] Student " << students[sIdx]->getName()
         << " (ID: " << studentId << ") registered to "
         << dept << " " << courseNum << "." << endl;
    return true;
}

bool DataManager::dropStudentFromCourse(int studentId,
                                        const string& dept, int courseNum) {
    int sIdx = findStudentIndex(studentId);
    if (sIdx == -1) {
        cout << "[DataManager] Student ID " << studentId
             << " not found." << endl;
        return false;
    }
    int cIdx = findCourseIndex(dept, courseNum);
    if (cIdx == -1) {
        cout << "[DataManager] Course " << dept << " " << courseNum
             << " not found." << endl;
        return false;
    }

    if (!courseRegs[cIdx]->removeStudent(studentId))
        return false;

    students[sIdx]->removeCourse(dept, courseNum);

    cout << "[DataManager] Student " << students[sIdx]->getName()
         << " (ID: " << studentId << ") dropped from "
         << dept << " " << courseNum << "." << endl;
    return true;
}

// ── Queries ───────────────────────────────────────────────────────────────────

bool DataManager::isStudentEnrolledInCourse(int studentId,
                                             const string& dept,
                                             int courseNum) const {
    int cIdx = findCourseIndex(dept, courseNum);
    if (cIdx == -1) return false;
    return courseRegs[cIdx]->isStudentEnrolled(studentId);
}

bool DataManager::isStudentAtUniversity(int studentId) const {
    return findStudentIndex(studentId) != -1;
}

// ── Utility ───────────────────────────────────────────────────────────────────

void DataManager::printAllStudents() const {
    cout << "\n========== All Students (" << numStudents << ") ==========" << endl;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (students[i] != 0) {
            students[i]->print();
            cout << endl;
        }
    }
}

void DataManager::printAllCourses() const {
    cout << "\n========== All Courses (" << numCourses << ") ==========" << endl;
    for (int i = 0; i < MAX_REG_COURSES; i++) {
        if (courseRegs[i] != 0) {
            courseRegs[i]->print();
            cout << endl;
        }
    }
}
