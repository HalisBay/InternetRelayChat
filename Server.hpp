#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <cstring>
#include <fcntl.h>
#include <vector>
#include <poll.h>
#include <stdexcept>


#define MAX_CONNECTIONS 42

class Server
{
private:
  const std::string   _host;
  const std::string	_port;
  const std::string	_password;
  int					_serverSocket;
    std::vector<struct pollfd> _pollfds;
    std::vector<User*> _users; // User sınıfını oluşturmayı unutma
    int                 setupSocket();          

public:
    Server(/* args */);
    Server(const std::string host, const std::string port, const std::string password);
    ~Server();

    void start();
    void handleEvents();
};