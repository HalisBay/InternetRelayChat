#ifndef LIST_HPP
#define LIST_HPP

#include "Command.hpp"  // Ensure this includes Commands

class List : public Command // Inherit from Commands
{
public:
	List();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif