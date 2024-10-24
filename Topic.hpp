#ifndef TOPIC_HPP
#define TOPIC_HPP

#include "Command.hpp"

class Topic : public Command
{
public:
	Topic();
	void execute(int client_fd);
	std::string getName() const;
	std::string description() const;
};

#endif
