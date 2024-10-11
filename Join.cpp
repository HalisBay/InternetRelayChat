#include "Join.hpp"

Join::Join()
{
}

void Join::execute(int client_fd)
{
	std::string str = ":" + _users->getNickName() + "!" + _users->getName() + "@"+ _server->getHost() + " JOIN " + _args[1] + "\r\n";
    _server->sendMessage(_users->getClientfd(), str);
}

std::string Join::getName() const
{
	return "JOIN";
}

std::string Join::description() const
{
	return  "JOIN: Used to add users to the channel";
}
