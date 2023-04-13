


#include "PasswordInput.h"

const std::string PasswordInput::getPassword() {
    return this->password;
}

void PasswordInput::input() {


#if BOOST_OS_LINUX
    termios old_settings, new_settings;
    tcgetattr(STDIN_FILENO, &old_settings);
    new_settings = old_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
#elif BOOST_OS_WINDOWS
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
#endif
    std::cin >> this->password;
    //std::getline(std::cin, this->password);

#if BOOST_OS_LINUX
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
#elif BOOST_OS_WINDOWS
    SetConsoleMode(hStdin, mode);
#endif


}
