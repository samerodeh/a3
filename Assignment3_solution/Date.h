#ifndef DATE_H
#define DATE_H

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date();
    Date(int month, int day, int year);
    ~Date();

    // Getters
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    // Setters
    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);

    void print() const;
};

#endif
