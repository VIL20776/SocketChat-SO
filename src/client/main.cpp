#include "client.hpp"

int main(int argc, char const *argv[])
{
    if (argc < 4 || argc > 4) {
        return 1;
    }

    std::string username = argv[1];
    const char* ip = argv[2];
    int port = std::stoi(std::string(argv[3]));

    Client client;
    client.connect_to(ip, port, username);

    bool connected = true;
    while (connected)
    {
        // Interfaz, manejo de chats y requests
    }
    

    return 0;
}
