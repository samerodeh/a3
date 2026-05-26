#include "person.h"
#include "date.h"
#include "course.h"


class Student: public Person {

    private: 

        int student_id;
        Date enrollment_date;   
        int num_of_courses_enrolled;
        Course* enrolled_arr[3];

    public: 

        Student(int student_id, Date enrollment_date, int num_of_courses_enrolled, Course* enrolled_arr[]);
        ~Student();

        int get_student_id() const;
        Date get_enrollment_date() const;
        int get_num_of_courses_enrolled() const;
        Course* get_enrolled_arr() const;


        void set_student_id(int student_id);
        void set_enrollment_date(Date enrollment_date);
        void set_num_of_courses_enrolled(int num_of_courses_enrolled);
        void set_enrolled_arr(Course* enrolled_arr[int]);

        void print();

        void add_course_to_enrolled_arr(Course course_number);

        void remove_course_to_enrolled_arr(Course course_number);
        

};