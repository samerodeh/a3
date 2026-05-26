Person::Person(std::string name, Date dob)
      : name(name), dob(dob)
      { 
      }

Person::~Person() {cout << "object destroyed !!";}


std::string Person::get_name() {return name;}
Date Person::get_dob() {return dob;}

void Person::set_name(std::string name) {this->name = name;}
void Person::set_dob(Date dob) {this->dob = dob;}

