#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "Server.hpp"  // Include Server class
#include <string>
#include <iostream>
#include "Utils.hpp"

class Command {
protected:
    Server* _server;
    User* _users;
public:
    virtual ~Command() {}
    Command();
    virtual void execute(int client_fd) = 0;
    virtual std::string getName() const = 0; // Saf sanal fonksiyon
    virtual std::string description() const = 0;

    void setServer(Server* server);
    void setUser(User* users);
};

#endif // COMMAND_HPP
