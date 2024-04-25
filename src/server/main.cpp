#include <string>
#include <iostream>

#include "server.hpp"

#define CONNECTIONS 40
#define THREADS 8

int main(int argc, char const *argv[])
{
    if (argc > 2 || argc < 3) {
        return 1;
    }

    std::string port = argv[1];

    Server server (std::stoi(port));

    if (server.run(CONNECTIONS, THREADS) < 0) {
        std::cerr << "Fallo en el servidor.\n";
        return 1;
    }

    return 0;
}
