#include "Privmsg.hpp"

Privmsg::Privmsg()
{
}

void Privmsg::execute()
{
}

std::string Privmsg::getName() const
{
	return "privmsg";
}

std::string Privmsg::description() const
{
	return BLUE "Privmsg : Sends a message to a specific user or channel";
}
