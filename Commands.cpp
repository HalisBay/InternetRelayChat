#include "Server.hpp"
#include "Commands.hpp"
#include "Command.hpp"
#include "Help.hpp"
#include "Quit.hpp"
#include "Join.hpp"
#include "Nick.hpp"
#include "Part.hpp"
#include "Privmsg.hpp"
#include "Ping.hpp"
#include "Pong.hpp"
#include "Notice.hpp"
#include "Topic.hpp"
#include "Kick.hpp"
#include "List.hpp"
#include "Names.hpp"
#include "User.hpp"
#include "Who.hpp"
#include <sys/socket.h>
#include <sstream>

Commands::Commands(Server* server) : _server(server) { 
    _commands.push_back(new Help());
	_commands.push_back(new Quit());
	_commands.push_back(new Join());
	_commands.push_back(new Nick());
	_commands.push_back(new Part());
	_commands.push_back(new Privmsg());
	_commands.push_back(new Notice());
	_commands.push_back(new Ping());
	_commands.push_back(new Pong());
	_commands.push_back(new Topic());
	_commands.push_back(new Kick());
	_commands.push_back(new List());
	_commands.push_back(new Names());
	_commands.push_back(new Who());
}

Commands::~Commands() {
    for (size_t i = 0; i < _commands.size(); ++i) {
        delete _commands[i];
    }
}

Command* Commands::commandFinder(const std::string &cmdName, User *it)
{
	std::vector<std::string> args = setArgs(cmdName);
	for(size_t i = 0; i < _commands.size(); i++)
	{
		if(cmdName != "" && _commands[i]->getName() == args[0])
		{

			_commands[i]->setServer(_server);
			_commands[i]->setUser(it);
			_commands[i]->setUserArgs(args);
			_commands[i]->execute((*it).getClientfd());
			break;
		}
		else if(args[0] == "PASS" || args[0] == "MODE")
		{
			break;
		}
		else if(cmdName != "" && i == _commands.size() -1)
		{
			_server->sendError((*it).getClientfd(),"Command not found\n");
		}
	}

	return 0;
}

std::vector<Command *> Commands::getCommends() const
{
	return _commands;
}

std::vector<std::string> Commands::setArgs(const std::string &msg) {
    std::vector<std::string> cpyArg;
    std::stringstream ss(msg);
    std::string arg;

    while (std::getline(ss, arg, ' ')) {
        if (!arg.empty()) {
            cpyArg.push_back(arg);
        }
    }

    return cpyArg;
}

