#include "server.hpp"

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <iostream>

Server::Server(int port) {
    this->address.sin_family = AF_INET;
    this->address.sin_port = htons(port);
    this->address.sin_addr.s_addr = INADDR_ANY;

    this->size = sizeof(this->address); 
}


int Server::run(int connections, int threads) {
    int server_socket = socket(AF_INET,SOCK_STREAM,0);
    if (server_socket < 0) {
        std::cerr << "Fallo al inicializar el socket.\n";
        return 1;
    }

    if (bind(server_socket, (sockaddr*) &this->address, this->size) < 0) {
        std::cerr << "Fallo al asignar una direccion al socket.\n";
        return 1;
    }

    if (listen(server_socket, connections) < 0) {
        std::cerr << "El socket no puede atender solicitudes.\n";
        return 1;
    }

    /* Manejo de requests con multi threading */
    
    if (close(server_socket) < 0) {
        std::cerr << "El socket no pudo ser cerrado correctamente.\n";
        return 1;
    }

    return 0;
}
