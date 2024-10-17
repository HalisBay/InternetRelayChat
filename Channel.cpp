#include "Channel.hpp"

Channel::Channel(std::string &channelName)
{
	_channelName = channelName;
}

Channel::~Channel()
{
}

void Channel::setChannelName(string channelName)
{
	_channelName = channelName;
}

void Channel::setTopicName(string topicName)
{
	_topicName = topicName;
}

void Channel::setUsers(User *user)
{
	_usersInChannel.push_back(user);
}

void Channel::setAdminName(string admin)
{
	_adminName = admin;
}


void Channel::removeUser(User* user) {
	std::cout << "deneme bebe" << std::endl;
    for (std::vector<User*>::iterator it = _usersInChannel.begin(); it != _usersInChannel.end(); ++it) {
		std::cout << *it << std::endl;
        if (*it == user) {
            _usersInChannel.erase(it);
            break;
        }
    }
}