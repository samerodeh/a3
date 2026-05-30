#include <iostream>
#include <string>


class Course {


    private: 

        // data members
        std::string department_name;
        int course_number;
        std::string course_name; 

    public: 
        Course(); // default constructor
        Course(std::string department_name, int course_number, std::string course_name); // constructor 
        ~Course(); // destructor

        // getters
        std::string get_department_name() const; 
        int get_course_number() const;
        std::string get_course_name() const;

        // setters
        void set_department_name(std::string department_name); 
        void set_course_number(int course_number ); 
        void set_course_name(std::string course_name); 

        void print();






};