#ifndef TOPIC_HPP
#define TOPIC_HPP

#include "Command.hpp"  // Ensure this includes Commands

class Topic : public Command // Inherit from Commands
{
public:
	Topic();
	void execute();
	std::string getName() const;
	std::string description() const;
};

#endif
