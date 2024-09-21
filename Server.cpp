#include "Server.hpp"

int Server::setupSocket()
{
    addrinfo hints, *serverInfo, *cp;
    int sock_fd;
    int optval = 1;

    memset(&hints,0,sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(this->_host.c_str(), this->_port.c_str(), &hints, &serverInfo) != 0)
        throw std::runtime_error("Error while getting address info!");
    
    for (cp = serverInfo; cp != NULL; cp = cp->ai_next)
    {
        sock_fd = socket(cp->ai_family, cp->ai_socktype, cp->ai_protocol);
        if (sock_fd < 0) {
            continue;
        }
                                                        //burada optval kullanmamızın sebebi int* bekliyor olması, işlevi sadece aktif etmek(1);
        if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) < 0) {
            close(sock_fd);
			freeaddrinfo(serverInfo);
            throw std::runtime_error("Error while setting socket options!");
        }
        
        if (bind(sock_fd, cp->ai_addr, cp->ai_addrlen) < 0) {
            close(sock_fd);
            continue;
        }
        break;
    }

    freeaddrinfo(serverInfo);

    if (cp == NULL)
        throw std::runtime_error("Failed to bind the socket!");

    if (listen(sock_fd, MAX_CONNECTIONS) < 0)
        throw std::runtime_error("Error while listening on the socket!");
    
    return sock_fd;

}

Server::Server(const std::string host, const std::string port, const std::string passwd)
{
    this->_host = host;
    this->_port = port;
    this->_password = passwd;
    this->_serverSocket = setupSocket();
}

void Server::start()
{
}
