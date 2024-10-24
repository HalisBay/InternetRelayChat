#ifndef LIST_HPP
#define LIST_HPP

#include "Command.hpp"

class List : public Command
{
public:
	List();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
