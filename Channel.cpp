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

// std::vector<User *> Channel::getUsers()
// {
// 	return _usersInChannel;
// }
