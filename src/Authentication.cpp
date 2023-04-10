

#include "Authentication.h"


Authentication::Authentication(const std::string &user_name, const std::string &password) : user_name(user_name),
                                                                                            password(password) {}

Login::Login(const std::string &user_name, const std::string &password) : Authentication(user_name, password) {}

bool Login::isPasswordCorrect() const {
    return Authorization::isCorrect(
            this->password,
            SqliteDataBaseService<Permission, std::size_t>::getInstance().get(
                    SqliteDataBaseService<User, std::size_t>::getInstance().getId(this->user_name)
            ).password
    );

}

bool Login::isUserNameCorrect() const {
    return SqliteDataBaseService<User, std::size_t>::getInstance().existsByName(this->user_name);

}


SignUp::SignUp(const std::string &user_name, const std::string &password) : Authentication(user_name, password) {}

void SignUp::registerUser() {
    SqliteDataBaseService<User, std::size_t>::getInstance().insert(User{.name=this->user_name});

    SqliteDataBaseService<Permission, std::size_t>::getInstance().insert(
            Permission{
                    .user_id=SqliteDataBaseService<User, std::size_t>::getInstance().getId(this->user_name),
                    .password=this->password
            }
    );
}


bool SignUp::isUserNameAlreadyExists(const std::string &user_name) {
    return SqliteDataBaseService<User, std::size_t>::getInstance().existsByName(user_name);

}
