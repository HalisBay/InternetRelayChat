#ifndef PONG_HPP
#define PONG_HPP

#include "Command.hpp"  // Ensure this includes Commands

class Pong : public Command // Inherit from Commands
{
public:
	Pong();
	void execute();
	std::string getName() const;
	std::string description() const;
};

#endif
