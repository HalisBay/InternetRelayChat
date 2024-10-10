#include "Channel.hpp"

Channel::Channel()
{
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
