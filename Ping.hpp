#ifndef PING_HPP
#define PING_HPP

#include "Command.hpp"  // Ensure this includes Commands

class Ping : public Command // Inherit from Commands
{
public:
	Ping();
	void execute();
	std::string getName() const;
	std::string description() const;
};

#endif
