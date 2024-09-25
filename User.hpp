#if !defined(USER_HPP)
#define USER_HPP

#include <iostream>
#include <string> // std::string kullanabilmek için ekledik

class User {
private:
    std::string _name;
    std::string _surname;
    std::string _nickName;

public:
	User();
    User(const std::string& name, const std::string& nickname, const std::string& surname);
    ~User();
    
    std::string getName() { return _name; }
    std::string getSurname() { return _surname; }
    std::string getNickName() { return _nickName; }
};

#endif // USER_HPP
