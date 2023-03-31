//
// Created by andriy on 3/27/23.
//

#include "Login.h"


Sign::Sign(const std::string &user_name, const std::string &password) : user_name(user_name), password(password) {}

Login::Login(const std::string &user_name, const std::string &password) : Sign(user_name, password) {}

bool Login::isPermissionConfirmed() const {
    Permission permission = SqliteDataBaseService<Permission,std::size_t>::getInstance().get(SqliteDataBaseService<User,std::size_t>::getInstance().getId(this->user_name));
    return Authorization::isCorrect(this->password,permission.password);

}

SignUp::SignUp(const std::string &user_name, const std::string &password) : Sign(user_name, password) {}

void SignUp::registerUser() {


}

bool SignUp::isAlreadyExists() {
    return
}