#include "student.h"
#include "course_registration.h"

class DataManager {

    private: 

        int num_enrolled;
        Student* students;
        CourseRegistration* courses;

    public: 

        DataManager();
        DataManager(int num_enrolled, Student students, CourseRegistration courses);
        ~DataManager();
        DataManager(const DataManager& other);

        int get_num_enrolled() {return num_enrolled;}
        
        bool enroll_to_uni();

        

        void print();
        


};