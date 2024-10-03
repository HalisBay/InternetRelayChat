#include "Kick.hpp"

Kick::Kick()
{
}

void Kick::execute()
{
}

std::string Kick::getName() const
{
	return "kick";
}

std::string Kick::description() const
{
	return RED "Kick 	: Removes a user from a specific channel";
}
