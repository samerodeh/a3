#include "client.h"

Client::Client(std::string client_name, Date *client_DOB)
      : 
        client_name(client_name),
        client_DOB(client_DOB)
    {
    }

Client::~Client() {cout << "Client object destroyed "}