#ifndef QUIT_HPP
#define QUIT_HPP

#include "Command.hpp"  // Ensure this includes Commands

class Quit : public Command // Inherit from Commands
{
public:
	Quit();
	void execute();
	std::string getName() const;
	std::string description() const;
};

#endif
