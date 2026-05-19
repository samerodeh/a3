#include <iostream>

class Date {

    private: 

        int string month;
        int day;
        int year;

    public: 

        Date(
            int month,
            int day,
            int year
        ); 

        ~Date();

        int get_month() {return month;}
        void set_month(int month) {this->month = month;}
        
        int get_day() {return day;}
        void set_day(int day) {this->day = day;}

        int get_year() {return day;}
        void set_year(int year) {this->year = year;}

        void print_date() const

};
