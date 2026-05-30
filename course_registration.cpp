#include "course_registration.h"

CourseRegistration::CourseRegistration() : Course(), max_size(0), num_enrolled(0), student_ids(nullptr) {}

CourseRegistration::CourseRegistration(int max_size)
                  : max_size(max_size)
                {
                    student_ids = new int[max_size];
                    for (int i = 0; i < max_size; i++) {
                      student_ids[i] = 0;
                    }
                }

CourseRegistration::~CourseRegistration() {

      cout << "CourseRegistration object destroyed ";
      delete[] student_ids;
      student_ids = nullptr;
}

int CourseRegistration::get_max_size() {return max_size;}

int CourseRegistration::get_num_enrolled() {return num_enrolled;}

bool CourseRegistration::register_to_course(int student_id) {

      if (num_enrolled > max_size) {

          cout << "this class is full ";
      }


      // check if student is alredy enrolled or not.
      if (is_student_enrolled(student_id) == false) {
              
              for (int i = 0; i < max_size; ++i) {

                    if (student_ids[i] == 0) {

                        student_ids[i] = student_id;
                        num_enrolled++;
                        return true;
                    }
              }
      }
}

bool CourseRegistration::remove_from_course(int student_id) {

  if (is_student_enrolled(student_id) ) {

    for (int i = 0; i < max_size; ++i) {

      if (student_ids[i] == student_id) {

        student_ids[i] = 0;
        num_enrolled--;
        return true;
      } 
    }
  } return false;
}   

bool CourseRegistration::is_student_enrolled(int student_id) {

      for(int i{0}; i < max_size; ++i) {

          if (student_ids[i] == student_id) {

            return true;
          }
          return false;
      }
}

