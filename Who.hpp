#ifndef WHO_HPP
#define WHO_HPP

#include "Command.hpp"

class Who : public Command
{
public:
	Who();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
