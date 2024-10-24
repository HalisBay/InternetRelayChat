#ifndef KICK_HPP
#define KICK_HPP

#include "Command.hpp"

class Kick : public Command
{
public:
	Kick();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
