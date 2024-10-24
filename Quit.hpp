#ifndef QUIT_HPP
#define QUIT_HPP

#include "Command.hpp"
#include "Commands.hpp"

class Quit : public Command
{
public:
	Quit();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
