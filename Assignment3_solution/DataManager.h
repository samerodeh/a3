#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "Student.h"
#include "CourseRegistration.h"

const int MAX_STUDENTS = 5000;
const int MAX_REG_COURSES = 200;

class DataManager {
private:
    int numStudents;
    int numCourses;
    Student*            students[MAX_STUDENTS];
    CourseRegistration* courseRegs[MAX_REG_COURSES];

    // Helper: find student index by id (-1 if not found)
    int findStudentIndex(int studentId) const;
    // Helper: find course index by dept and number (-1 if not found)
    int findCourseIndex(const string& dept, int courseNum) const;

public:
    DataManager();
    ~DataManager();

    // University enrollment
    bool enrollStudent(Student* student);
    bool removeStudent(int studentId);

    // Course management
    bool addCourse(CourseRegistration* cr);
    bool removeCourse(const string& dept, int courseNum);

    // Student-course operations
    bool registerStudentToCourse(int studentId, const string& dept, int courseNum);
    bool dropStudentFromCourse(int studentId, const string& dept, int courseNum);

    // Queries
    bool isStudentEnrolledInCourse(int studentId, const string& dept, int courseNum) const;
    bool isStudentAtUniversity(int studentId) const;

    // Utility
    void printAllStudents() const;
    void printAllCourses()  const;
};

#endif
