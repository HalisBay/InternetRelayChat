#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include "Utils.hpp"
class Command {
public:
    virtual ~Command() {}
	virtual void execute() = 0;
    virtual std::string getName() const = 0; // Saf sanal fonksiyon
	virtual std::string description() const = 0;
};

#endif
