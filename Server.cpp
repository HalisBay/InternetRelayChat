#include "Server.hpp"

void printSocketInfo(int sock_fd) {
    sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    
    if (getsockname(sock_fd, (sockaddr *)&addr, &addrlen) == -1) {
        std::cerr << "Error getting socket name: " << strerror(errno) << std::endl;
        return;
    }

    std::cout << "Socket is bound to IP: " << inet_ntoa(addr.sin_addr)
              << " on port: " << ntohs(addr.sin_port) << std::endl;
}


int Server::setupSocket()
{
    addrinfo hints, *serverInfo, *cp;
    int sock_fd;
    int optval = 1;

    // ip bilgilerini set eder
    memset(&hints,0,sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(_host.c_str(), _port.c_str(), &hints, &serverInfo) != 0)
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

        if (bind(sock_fd, cp->ai_addr, cp->ai_addrlen) < 0) { //socketi adres ve port ile ilişkilendiriyor atıyorum localhost:9000 ile soketi bağlıyor 
            close(sock_fd);
            continue;
        }
        printSocketInfo(sock_fd);
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
    _host = host;
    _port = port;
    _password = passwd;
    _serverSocket = setupSocket();
    // hata kontrolü olabilir
}

Server::~Server()
{
}

void Server::start()
{
    struct pollfd newPollfd;
    newPollfd.fd = _serverSocket;
    newPollfd.events = POLLIN;

    if(fcntl(_serverSocket, F_SETFL,O_NONBLOCK)== -1) // fdlerin özelliklerini ayarlar
        throw std::runtime_error("Error while setting socket non-blocking!");

    _pollfds.push_back(newPollfd);
    std::cout<< "Server Started" << std::endl;

    while(true)
    {                                                      //timeout eklenebilir
        int numReady = poll(&_pollfds[0], _pollfds.size(), -1);//poll fd olaylarını izler
        if(numReady == -1)
            throw std::runtime_error("Error: while polling!");
        this->handleEvents();
    }
}

void Server::handleEvents()
{
    for (unsigned long i = 0; i < _pollfds.size(); ++i) {
        struct pollfd& pfd = _pollfds[i]; // pfd burada tanımlanıyor

        if (pfd.revents & POLLIN) {
            if (pfd.fd == _serverSocket) {
                std::cout << "\033[35m" << "rainbow mustafa" << "\033[0m" << std::endl;
                sockaddr_storage clientAddr;
                socklen_t addrlen = sizeof(clientAddr);
                int clientSock = accept(_serverSocket, (sockaddr*)&clientAddr, &addrlen);
                
                if (clientSock >= 0) {
                    // Kullanıcı bilgilerini burada belirleyin, örneğin varsayılan bir kullanıcı ekleyin
                    addUser();
                    // std::string userInput;
                    // std::cout << "Type -Help- to see commands";
                    // std::getline(std::cin, userInput);
                    // for (size_t i = 0; i < _commands->size(); i++) {
		            //     if (userInput == _commands[i]->getName()) {
                    //         std::cout << "mustafa g0dden" << std::endl;
                            //_commands[i]->execute(); her command için execute, sonra yapılabilir
                        }
                // addUser();
                    }
            }
            else {
                // varolan kullanıcı işlemleri
            }
        }
        
        // if (pfd.revents & POLLHUP) {
        //     // Kullanıcı çıkış işlemi
        // }
    }
void Server::addUser()
{
	User* newUser = new User("a","b","c");
	_users.push_back(newUser);
	std::cout << "User added: " << newUser->getNickName() << std::endl;
}