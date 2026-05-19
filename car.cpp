#include "car.h"

Car::Car(
        std::string car_model,
        std::string car_color,
        std::string car_serial_num,
        int car_model_year,
        int car_milage,
        int car_price
    )  
      : car_model(car_model),
        car_color(car_color),
        car_serial_num(car_serial_num),
        car_model_year(car_model_year),
        car_milage(car_milage),
        car_price(car_price)
    { 
    }

Car::~Car() {}


void Car::print_car() const {

    std::cout << "the car has information: " 
              << month << std::setw(2) 
              << day << std::setw(2) 
              << year;
              
}