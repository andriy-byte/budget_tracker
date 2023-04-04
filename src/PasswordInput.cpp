//
// Created by andriy on 4/4/23.
//


#include "PasswordInput.h"

const std::string PasswordInput::getPassword() {
    return this->password;
}

void PasswordInput::input() {


#if BOOST_OS_LINUX
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#elif BOOST_OS_WINDOWS
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
#endif
    getline(std::cin, this->password);

#if BOOST_OS_LINUX
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#elif BOOST_OS_WINDOWS
    SetConsoleMode(hStdin, mode);
#endif


}
