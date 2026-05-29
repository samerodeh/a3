#include "course.h"


class CourseRegistration : public Course {


    private: 

        int maxSize;
        int numEnrolled;
        int* studentIds;


    public:

        CourseRegistration(int max);    
        ~CourseRegistration();

        

        

};