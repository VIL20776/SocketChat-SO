#pragma once

#include <string>

class Client 
{
private:
    int client_socket;

    std::string username;
    std::string status;

public:
    Client();
    ~Client();

    int connect_to(const char* ip, int port, std::string username);
    int handle_chat(/*Params*/);

};