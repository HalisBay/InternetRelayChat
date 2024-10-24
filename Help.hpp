#ifndef HELP_HPP
#define HELP_HPP

#include "Command.hpp"

class Help : public Command
{
public:
	Help();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
