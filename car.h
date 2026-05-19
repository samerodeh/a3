#include <string>
#include <iostream>

class Car {

    private:  

        std::string car_model;
        std::string car_color;
        std::car_serial_num;
        int car_model_year;
        int car_milage;
        int car_price; 

    public: 

        Car(
            std::string car_model,
            std::string car_color,
            std::string car_serial_num,
            int car_model_year,
            int car_milage,
            int car_price
        );

        ~Car();


        std::string get_car_model() {return car_model;}
        void set_car_model(std::string car_model) {this->car_model = car_model;}

        std::string get_car_color() {return car_color;}
        void set_car_color(std::string car_color) {this->car_color = car_color;}
        
        std::string get_car_serial_num() {return car_serial_num;}
        void set_car_serial_num(std::string car_serial_num) {this->car_serial_num = car_serial_num;}

        int get_car_model_year() {return car_model_year;}
        void set_car_model_year(int car_model_year) {this->car_model_year = car_model_year;}

        int get_car_milage() {return car_milage;}
        void set_car_milage(int car_milage) {this->car_milage = car_milage;}

        int get_car_price() {return car_price;}
        void set_car_price(int car_price) {this->car_price = car_price;}

        void print_car() const
        

};