#include "client.hpp"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <stdexcept>
#include <string>

Client::Client()
{
    this->client_socket = socket(AF_INET,SOCK_STREAM,0);
    if (this->client_socket < 0)
        throw std::runtime_error("No se pudo inicializar el socket");
}

Client::~Client()
{
    if (close(this->client_socket) < 0)
        throw std::runtime_error("No se pudo cerrar el socket");
}

int Client::connect_to(const char* ip, int port, std::string username)
{
    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(ip);

    socklen_t size = sizeof(server_address);

    connect(this->client_socket, (sockaddr*) &server_address, size);
}

