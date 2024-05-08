#pragma once

#include <vector>
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
    std::vector<int> client_sockets;
    
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
    Esta pendiente de las nuevas conexiones y agrega los sockets al vector @client_sockets
    */
    int accept_connections();

    /*
    Escucha los sockets de las conexiones habilitadas en @conn_sockets e internamente
    maneja los mensajes entrantes y salientes.
    */
    int handle_connections(std::vector<int> &conn_sockets);

};

