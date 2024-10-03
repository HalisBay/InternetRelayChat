#include "Names.hpp"

Names::Names()
{
}

void Names::execute()
{
}

std::string Names::getName() const
{
	return "names";
}

std::string Names::description() const
{
	return RED "Names 	: Shows the list of users in a channel" RESET;
}
