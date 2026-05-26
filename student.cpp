


Student::Student(int student_id, Date enrollment_date, int num_of_courses_enrolled, Course* enrolled_arr[]);
Student::~Student();

int Student::get_student_id() {return student_id;}
Date Student::get_enrollment_date() {return enrollment_date;}
int Student::get_num_of_courses_enrolled() {return num_of_courses_enrolled;}
Course* Student::get_enrolled_arr() {return enrolled_arr;}

void Student::set_student_id(int student_id) {this->student_id = student_id;}
void Student::set_enrollment_date(Date enrollment_date) {this->enrollment_date = enrollment_date;}
void Student::set_num_of_courses_enrolled(int num_of_courses_enrolled) {this->num_of_courses_enrolled = num_of_courses_enrolled;}
void Student::set_enrolled_arr(Course* enrolled_arr[int]) {this->enrolled_arr = enrolled_arr;}

void Student::add_course_to_enrolled_arr(Course* course) {

    if (num_of_courses_enrolled < 4) {

        enrolled_arr[num_of_courses_enrolled] = course;
         num_of_courses_enrolled++;

    } else cout << "maximum amount of courses enrolled! ! ! ! ";

}

void Student::remove_course_from_enrolled_arr(Course course) {

    for (int i = 0; i < 4; i++) {
        
        if (course == *enrolled_arr[i]) {

            enrolled_arr[i] = nullptr;        
            num_of_courses_enrolled--;
            return;
            
        }    

    } 

}

