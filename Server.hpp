#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <cstring>


#define MAX_CONNECTIONS 42

class Server
{
private:
	const std::string   _host;
	const std::string	_port;
	const std::string	_password;
	int					_serverSocket;

    int                 setupSocket();          
   
public:
    Server(/* args */);
    Server(const std::string host, const std::string port, const std::string password);
    ~Server();
    
    void    start();
};