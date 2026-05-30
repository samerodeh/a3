#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course {
private:
    string departmentName;
    int    courseNumber;
    string courseName;

public:
    Course();
    Course(const string& dept, int number, const string& name);
    virtual ~Course();

    // Getters
    string getDepartmentName() const;
    int    getCourseNumber()   const;
    string getCourseName()     const;

    // Setters
    void setDepartmentName(const string& dept);
    void setCourseNumber(int number);
    void setCourseName(const string& name);

    virtual void print() const;
};

#endif
