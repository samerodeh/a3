#include <iostream>
#include "DataManager.h"
using namespace std;

int main() {

    cout << "============================================================" << endl;
    cout << "       University Student Registration System               " << endl;
    cout << "============================================================\n" << endl;

    // ── 1. Create the DataManager ─────────────────────────────────────────────
    DataManager dm;

    // ── 2. Create courses and add them ───────────────────────────────────────
    cout << "--- Adding Courses ---" << endl;
    CourseRegistration* cr1 = new CourseRegistration("COEN", 244, "Programming Methodology", 3);
    CourseRegistration* cr2 = new CourseRegistration("COEN", 346, "Operating Systems",       2);
    CourseRegistration* cr3 = new CourseRegistration("MATH", 201, "Calculus",                5);
    CourseRegistration* cr4 = new CourseRegistration("ELEC", 275, "Signals and Systems",     4);

    dm.addCourse(cr1);
    dm.addCourse(cr2);
    dm.addCourse(cr3);
    dm.addCourse(cr4);

    // ── 3. Create students and enroll them at the university ─────────────────
    cout << "\n--- Enrolling Students ---" << endl;

    Date dob1(3, 15, 2002), enroll1(9, 1, 2021);
    Student* s1 = new Student("Alice Martin",   dob1, 1001, enroll1);

    Date dob2(7, 22, 2001), enroll2(9, 1, 2020);
    Student* s2 = new Student("Bob Tremblay",   dob2, 1002, enroll2);

    Date dob3(11, 5, 2003), enroll3(1, 15, 2022);
    Student* s3 = new Student("Clara Nguyen",   dob3, 1003, enroll3);

    Date dob4(4, 30, 2002), enroll4(9, 1, 2021);
    Student* s4 = new Student("David Chen",     dob4, 1004, enroll4);

    dm.enrollStudent(s1);
    dm.enrollStudent(s2);
    dm.enrollStudent(s3);
    dm.enrollStudent(s4);

    // Duplicate enroll test
    dm.enrollStudent(s1);

    // ── 4. Register students to courses ──────────────────────────────────────
    cout << "\n--- Registering Students to Courses ---" << endl;

    dm.registerStudentToCourse(1001, "COEN", 244);
    dm.registerStudentToCourse(1001, "COEN", 346);
    dm.registerStudentToCourse(1001, "MATH", 201);

    dm.registerStudentToCourse(1002, "COEN", 244);
    dm.registerStudentToCourse(1002, "MATH", 201);
    dm.registerStudentToCourse(1002, "ELEC", 275);

    dm.registerStudentToCourse(1003, "COEN", 244);
    dm.registerStudentToCourse(1003, "COEN", 346);   // fill COEN 346 (max=2)

    dm.registerStudentToCourse(1004, "COEN", 346);   // should fail — course full
    dm.registerStudentToCourse(1004, "ELEC", 275);
    dm.registerStudentToCourse(1004, "MATH", 201);

    // Duplicate registration test
    dm.registerStudentToCourse(1001, "COEN", 244);

    // ── 5. Print state ────────────────────────────────────────────────────────
    dm.printAllCourses();
    dm.printAllStudents();

    // ── 6. Query enrollment ───────────────────────────────────────────────────
    cout << "--- Enrollment Queries ---" << endl;

    cout << "Is student 1001 at university? "
         << (dm.isStudentAtUniversity(1001) ? "Yes" : "No") << endl;

    cout << "Is student 9999 at university? "
         << (dm.isStudentAtUniversity(9999) ? "Yes" : "No") << endl;

    cout << "Is student 1001 enrolled in COEN 244? "
         << (dm.isStudentEnrolledInCourse(1001, "COEN", 244) ? "Yes" : "No") << endl;

    cout << "Is student 1004 enrolled in COEN 346? "
         << (dm.isStudentEnrolledInCourse(1004, "COEN", 346) ? "Yes" : "No") << endl;

    // ── 7. Drop courses ───────────────────────────────────────────────────────
    cout << "\n--- Dropping Courses ---" << endl;
    dm.dropStudentFromCourse(1001, "COEN", 346);
    dm.dropStudentFromCourse(1002, "MATH", 201);
    dm.dropStudentFromCourse(1001, "ELEC", 275);  // not registered — should fail

    dm.printAllCourses();
    dm.printAllStudents();

    // ── 8. Test max courses per student (4) ───────────────────────────────────
    cout << "--- Testing Max 4 Courses per Student ---" << endl;
    dm.registerStudentToCourse(1004, "COEN", 244);
    dm.registerStudentToCourse(1004, "COEN", 346);   // 346 has a free slot now
    dm.registerStudentToCourse(1004, "COEN", 244);   // duplicate — should fail

    // ── 9. Remove a course from the system ───────────────────────────────────
    cout << "\n--- Removing a Course from the System ---" << endl;
    dm.removeCourse("MATH", 201);

    // ── 10. Remove students from the university ───────────────────────────────
    cout << "\n--- Removing Students from the University ---" << endl;
    dm.removeStudent(1003);
    dm.removeStudent(9999);   // non-existent student

    dm.printAllStudents();
    dm.printAllCourses();

    // ── 11. DataManager destructor cleans up everything ───────────────────────
    cout << "\n--- Program ending: DataManager destructor fires ---" << endl;
    // dm goes out of scope here and deletes all remaining objects

    return 0;
}
