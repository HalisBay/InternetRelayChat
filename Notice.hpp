#ifndef NOTICE_HPP
#define NOTICE_HPP

#include "Command.hpp"

class Notice : public Command
{
public:
	Notice();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
