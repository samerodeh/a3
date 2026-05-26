Course::Course(std::string department_name, int course_number, std::string course_name;) 
      : department_name(department_name), course_number(course_number), course_name(course_name)
      {
      }

Course::~Course() {cout << "object destroyed";}

std::string Course::get_department_name() const {return std::string department_name;}
int Course::get_course_number() const {return int course_number;}
std::string Course::get_course_name() const {return std::string course_name;}

void Course::set_department_name(std::string department_name) {this->department_name = department_name;}
void Course::set_course_number(int course_number) {this->course_number = course_number;}
void Course::set_course_name(std::string course_name) {this->course_name = course_name;}

void Course::print() {

    cout << 

}



