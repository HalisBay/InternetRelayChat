#ifndef NICK_HPP
#define NICK_HPP

#include "Command.hpp"  // Ensure this includes Commands

class Nick : public Command // Inherit from Commands
{
public:
	Nick();
	void execute();
	std::string getName() const;
	std::string description() const;
};

#endif
