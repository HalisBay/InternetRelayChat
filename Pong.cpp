#include "Pong.hpp"

Pong::Pong()
{
}

void Pong::execute(int client_fd)
{
	// std::cout << _users->getNickName() << "mustmustumsutmustmustu"<<std::endl;
	// std::string message = ":" + _users->getNickName()+ "!"+ _users->getName() + "@" + _server->getHost()+ " PONG :" + _users->getNickName();
	// _server->sendMessage(client_fd, message);   
}

std::string Pong::getName() const
{
	return "PONG";
}

std::string Pong::description() const
{
	return  "PONG: It responds to the ping message from the server";
}
