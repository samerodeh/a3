#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"
#include "Date.h"

const int MAX_COURSES = 4;

class Student : public Person {
private:
    int     studentId;
    Date    enrollmentDate;
    int     numCourses;
    Course* courses[MAX_COURSES];   // pointers to enrolled courses

public:
    Student();
    Student(const string& name, const Date& dob,
            int id, const Date& enrollDate);
    ~Student();

    // Getters
    int  getStudentId()      const;
    Date getEnrollmentDate() const;
    int  getNumCourses()     const;
    Course* getCourse(int index) const;

    // Setters
    void setStudentId(int id);
    void setEnrollmentDate(const Date& date);

    // Course management
    bool addCourse(Course* course);
    bool removeCourse(const string& dept, int courseNum);

    void print() const override;
};

#endif
