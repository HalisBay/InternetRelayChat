#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "Server.hpp"
#include <string>
#include <iostream>
class Command {
protected:
    Server* _server;
    User* _users;
    std::vector <std::string> _args;
public:
    virtual ~Command() {}
    Command();
    virtual void execute(int client_fd) = 0;
    virtual std::string getName() const = 0;
    virtual std::string description() const = 0;

    void setServer(Server* server);
    void setUser(User* users);
    void setUserArgs(std::vector<std::string> args);
};

#endif // COMMAND_HPP
