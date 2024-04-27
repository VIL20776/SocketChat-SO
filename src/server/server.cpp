#include "server.hpp"

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <stdexcept>
#include <iostream>

Server::Server() {
    this->server_socket = socket(AF_INET,SOCK_STREAM,0);
    if (this->server_socket < 0) 
        throw std::runtime_error("Fallo al inicializar el socket");
}

Server::~Server()
{
    if (close(this->server_socket) < 0)
        throw std::runtime_error("No se pudo cerrar el socket");
}

int Server::init(int port, int connections, int threads) {

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;

    socklen_t size = sizeof(address); 

    if (bind(server_socket, (sockaddr*) &address, size) < 0) {
        std::cerr << "Fallo al asignar una direccion al socket.\n";
        return 1;
    }

    if (listen(server_socket, connections) < 0) {
        std::cerr << "El socket no puede atender solicitudes.\n";
        return 1;
    }

    return 0;
}
