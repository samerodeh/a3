#include "course.h"


class CourseRegistration : public Course {


    private: 

        int max_size;
        int num_enrolled;
        int* student_ids;


    public:

        CourseRegistration();
        CourseRegistration(int max_size);
        ~CourseRegistration();

        // getters
        int get_max_size() const;
        int get_num_enrolled() const;
        // setters
        void set_max_size(int max_size);
        
        

};