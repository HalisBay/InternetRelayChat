#ifndef PING_HPP
#define PING_HPP

#include "Command.hpp"

class Ping : public Command
{
public:
	Ping();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
