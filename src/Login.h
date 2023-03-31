//
// Created by andriy on 3/27/23.
//

#ifndef BUDGET_TRACKER_LOGIN_H
#define BUDGET_TRACKER_LOGIN_H


#include <string>
#include "SqliteDataBaseService.h"
#include "Authorization.h"

class Sign{

public:
    Sign(const std::string &user, const std::string &password);

    Sign()=delete;
    Sign& operator=(const Sign&) = delete;
    Sign(const Sign&)=delete;


protected:

    std::string user_name, password;
};


class Login: public Sign{


public:
    bool isPermissionConfirmed() const;
    Login(const std::string &user_name, const std::string &password);
};



class SignUp: public Sign{
public:
    SignUp(const std::string &user_name, const std::string &password);
    void registerUser();
    bool isAlreadyExists();

};
#endif //BUDGET_TRACKER_LOGIN_H
