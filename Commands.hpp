#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <vector>
#include "User.hpp"
#include "Server.hpp"

class Command;

class Commands {
private:
    Server* _server;
    std::vector<Command*> _commands;
public:
    Commands(Server* server);
    virtual ~Commands();
    Command* commandFinder(const std::string& cmdName, User* it);
    std::vector<Command*> getCommends() const;
    std::vector<std::string> setArgs(const std::string &msg);
};

#endif // COMMANDS_HPP
