#ifndef JOIN_HPP
#define JOIN_HPP

#include "Command.hpp"

class Join : public Command 
{
public:
	Join();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
