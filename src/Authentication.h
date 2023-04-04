

#ifndef BUDGET_TRACKER_AUTHENTICATION_H
#define BUDGET_TRACKER_AUTHENTICATION_H


#include <string>
#include <optional>
#include "SqliteDataBaseService.h"
#include "Authorization.h"

#define MIN_USER_ID 1

enum AuthenticationStatus {
    DENIED, ACCEPT
};

class Authentication {

public:
    Authentication(const std::string &user, const std::string &password);

    Authentication() = delete;

    Authentication &operator=(const Authentication &) = delete;

    Authentication(const Authentication &) = delete;


protected:

    std::string user_name, password;
};


class Login : public Authentication {


public:
    bool isUserNameCorrect() const;

    bool isPasswordCorrect() const;

    Login(const std::string &user_name, const std::string &password);
};


class SignUp : public Authentication {
public:
    SignUp(const std::string &user_name, const std::string &password);

    static bool isUserNameAlreadyExists(const std::string &user_name);

    void registerUser();

    bool isAlreadyExists();

};

#endif //BUDGET_TRACKER_AUTHENTICATION_H
