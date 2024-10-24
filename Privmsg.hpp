#ifndef PRIVMSG_HPP
#define PRIVMSG_HPP

#include "Command.hpp"

class Privmsg : public Command
{
public:
	Privmsg();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
