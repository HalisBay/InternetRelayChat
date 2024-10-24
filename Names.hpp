#ifndef NAMES_HPP
#define NAMES_HPP

#include "Command.hpp"

class Names : public Command
{
public:
	Names();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
