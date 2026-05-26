Date::Date(int month, int day, int year)
    : month(month), day(day), year(year)
    {
    }

Date::~Date() {

    cout << "object destroyed."

}

int Date::get_month() {return month;}
int Date::get_day() {return day;}
int Date::get_year() {return year;}

void Date::set_month(int month) {this->month = month;}
void Date::set_day(int day) {this->day = day;}
void Date::set_year(int year) {this->year = year;}

void Date::print() {

    cout << "date: " 
         << get_month() << "/" 
         << get_day() << "/"
         << get_year();

}

