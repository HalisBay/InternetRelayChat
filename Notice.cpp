#include "Notice.hpp"

Notice::Notice()
{
}

void Notice::execute()
{
}

std::string Notice::getName() const
{
	return "notice";
}

std::string Notice::description() const
{
	return RED "Notice  : Sends a notification message to the target (user or channel)";
}
