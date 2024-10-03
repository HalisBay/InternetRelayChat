#include "Quit.hpp"

Quit::Quit()
{
}

void Quit::execute()
{
}

std::string Quit::getName() const
{
	return "Quit";
}

std::string Quit::description() const
{
	return BLUE "Quit 	: Allows you to exit the program";
}
