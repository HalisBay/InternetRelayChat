#ifndef NICK_HPP
#define NICK_HPP

#include "Command.hpp"

class Nick : public Command
{
public:
	Nick();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
