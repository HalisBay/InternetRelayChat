#ifndef PART_HPP
#define PART_HPP

#include "Command.hpp"

class Part : public Command
{
public:
	Part();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
