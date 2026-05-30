#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Date.h"
using namespace std;

class Person {
private:
    string name;
    Date   dateOfBirth;

public:
    Person();
    Person(const string& name, const Date& dob);
    virtual ~Person();

    // Getters
    string getName()        const;
    Date   getDateOfBirth() const;

    // Setters
    void setName(const string& name);
    void setDateOfBirth(const Date& dob);

    virtual void print() const;
};

#endif
