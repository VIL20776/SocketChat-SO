#include <string>
#include <iostream>

#include "server.hpp"

#define CONNECTIONS 40
#define THREADS 8

int main(int argc, char const *argv[])
{
    if (argc < 2 || argc > 2) {
        return 1;
    }

    std::string port = argv[1];

    Server server;

    if (server.init(std::stoi(port), CONNECTIONS, THREADS) < 0) {
        std::cerr << "Fallo al iniciar el servidor.\n";
        return 1;
    }

    bool running = true;
    while (running)
    {
        /* Manejo de threads de usuarios con mutithreading */
    }
    

    return 0;
}
