#if !defined(CHANNEL_HPP)
#define CHANNEL_HPP
#include <iostream>
#include <string>
#include <vector>

using std::string;

class Channel
{
private:
	string _channelName;
	string _topicName;
	//TODO: password alanı için her şeyi kanal mı ypıyor.
	std::vector<Channel*> _channel; // gerek var mı bilmiyom -H.

public:
	Channel(/* args */);
	~Channel();
	void setChannelName(string channelName);
	void setTopicName(string topicName);
	string getChannelName() { return _channelName; }
    string getTopicName() { return _topicName; }
};

#endif // CHANNEL_HPP
