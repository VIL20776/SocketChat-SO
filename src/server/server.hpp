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
    
    int init(int port, int connections, int threads);
    int handle_user(/*Params*/);
};

