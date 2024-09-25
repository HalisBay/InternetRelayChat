#include "User.hpp"

User::User()
{
}

User::User(const std::string &name, const std::string &nickname, const std::string &surname)
{
	_name = name;
	_surname = surname;
	_nickName = nickname;
}

User::~User()
{
}
