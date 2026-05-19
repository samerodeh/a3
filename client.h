#include <string>

class Client {

    private: 

        std::string client_name;
        Date *client_DOB; 

    public: 

        Client(std::string client_name, Date *client_DOB)

        ~Client() // destructor 
        
        std::string get_client_name() {return client_name;}
        void set_client_name() {this-> client_name = client_name;}

        Date get_client_DOB() {return client_DOB;}
        void set_client_DOB() {this-> client_DOB = client_DOB;}

        void print_client() const

};