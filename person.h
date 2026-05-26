#include "date.h"


class Person {

    private: 
        
        std::string name;
        Date dob;

    public: 
    
        Person(std::string name, Date DOB);
        ~Person();

        std::string get_name();
        Date get_dob();

        void set_name(std::string name);
        void set_dob(Date dob)

        void print();



};