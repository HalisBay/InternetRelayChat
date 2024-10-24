#include "Quit.hpp"
#include <iostream>

Quit::Quit()
{
}

void Quit::execute(int client_fd)
{
	Commands *partcommand = _server->getCommands();
	std::vector<std::string> userChannels = _users->getChannelName();
	for (std::vector<std::string>::iterator it = userChannels.begin(); it != userChannels.end(); ++it)
	{
		if((*it).data() && (*it).data()[0] != '\0')
		{
			partcommand->commandFinder("PART " + *it, _users);
		}
	}
	_server->removeUserAndFd(client_fd);
}

std::string Quit::getName() const
{
	return "QUIT";
}

std::string Quit::description() const
{
	return  "QUIT: Allows you to exit the program";
}
