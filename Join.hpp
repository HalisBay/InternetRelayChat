#ifndef JOIN_HPP
#define JOIN_HPP

#include "Command.hpp"  // Ensure this includes Commands

class Join : public Command // Inherit from Commands
{
public:
	Join();
	void execute();
	std::string getName() const;
	std::string description() const;
};

#endif
