#pragma once

#include <sys/socket.h>
#include <netinet/ip.h>

#include <map>

class Server
{
private:
    //Server props
    sockaddr_in address;
    socklen_t size;

    //Server data
    

public:
    Server(int port);
    // ~Server();
    int run(int connections, int threads);
};

