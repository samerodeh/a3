#ifndef COURSEREGISTRATION_H
#define COURSEREGISTRATION_H

#include "Course.h"

class CourseRegistration : public Course {
private:
    int  maxSize;
    int  numEnrolled;
    int* studentIds;    // dynamically allocated array of size maxSize

public:
    CourseRegistration();
    CourseRegistration(const string& dept, int number, const string& name, int maxSize);
    ~CourseRegistration();
        
    // Getters
    int getMaxSize()     const;
    int getNumEnrolled() const;

    // Setters
    void setMaxSize(int size);

    // Registration management
    bool registerStudent(int studentId);
    bool removeStudent(int studentId);
    bool isStudentEnrolled(int studentId) const;

    void print() const override;
};

#endif
