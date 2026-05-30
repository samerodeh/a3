#include "Person.h"
#include <iostream>
using namespace std;

Person::Person() : name("") {}

Person::Person(const string& name, const Date& dob)
    : name(name), dateOfBirth(dob) {}

Person::~Person() {}

string Person::getName()        const { return name; }
Date   Person::getDateOfBirth() const { return dateOfBirth; }

void Person::setName(const string& n)   { name = n; }
void Person::setDateOfBirth(const Date& dob) { dateOfBirth = dob; }

void Person::print() const {
    cout << "Name: " << name << ", DOB: ";
    dateOfBirth.print();
}
