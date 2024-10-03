#include "Help.hpp"
#include "Utils.hpp"
#include "Commands.hpp"


Help::Help()
{
}

void Help::execute()
{
	Commands cmdManager;

	std::vector<Command*> commands = cmdManager.getCommends();
	std::cout << "for dışı" <<std::endl;
	for(size_t i = 0; i < commands.size(); i++)
	{
		std::cout << commands[i]->description()<< std::endl;
		std::cout << "for içi" << std::endl;
	}
}

std::string Help::getName() const
{
	return "help";
}

std::string Help::description() const
{
	return RED "Help 	: Shows descriptions of commands";
}