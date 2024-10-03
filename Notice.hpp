#ifndef NOTICE_HPP
#define NOTICE_HPP

#include "Command.hpp"  // Ensure this includes Commands

class Notice : public Command // Inherit from Commands
{
public:
	Notice();
	void execute();
	std::string getName() const;
	std::string description() const;
};

#endif
