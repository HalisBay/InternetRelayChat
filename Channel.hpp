#if !defined(CHANNEL_HPP)
#define CHANNEL_HPP
#include <iostream>
#include <string>
#include <vector>
#include "User.hpp"
using std::string;

class Channel
{
private:
	string _channelName;
	string _topicName;
	std::vector<User *> _usersInChannel;
	//TODO: password alanı için her şeyi kanal mı ypıyor.

public:
	Channel(std::string &channelName);
	~Channel();
	void setChannelName(string channelName);
	void setTopicName(string topicName);
	string getChannelName() { return _channelName; }
    string getTopicName() { return _topicName; }
	std::vector<User *> getUsers() {return _usersInChannel;}
	void setUsers(User *user);
	//std::vector<User *> getUsers();
};

#endif // CHANNEL_HPP
