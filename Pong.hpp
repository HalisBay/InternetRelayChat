#ifndef PONG_HPP
#define PONG_HPP

#include "Command.hpp"

class Pong : public Command
{
public:
	Pong();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
