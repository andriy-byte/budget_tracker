

#ifndef BUDGET_TRACKER_PASSWORD_INPUT_H
#define BUDGET_TRACKER_PASSWORD_INPUT_H

#include<string>
#include <boost/predef.h>
#include <iostream>

#if BOOST_OS_WINDOWS
#include <windows.h>
#elif BOOST_OS_LINUX

#include <termios.h>
#include <unistd.h>

#endif

class PasswordInput {
public:
    PasswordInput() = default;

    void input();

    const std::string getPassword();

private:
    std::string password;
};

#endif // BUDGET_TRACKER_PASSWORD_INPUT_H