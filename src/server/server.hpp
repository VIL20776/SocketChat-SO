#pragma once

#include <string>
#include <map>

typedef struct UserData {
    std::string ip;
    std::string status;
};

class Server
{
private:
    int server_socket;
    
    std::map<std::string, UserData> user_list;
    std::map<std::string, std::string> chats;

public:
    Server();
    ~Server();
    
    /*
    Asocia una direccion IP y puerto disponibles al socket del servidor. Ademas
    determina la cantidad de conecciones que se pueden realizar.
    */
    int init(int port, int connections);

    /*
    Maneja los Request de un usuario en particular
    */
    int handle_user(/*Params*/);
};

