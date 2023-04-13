//
// Created by andriy on 4/12/23.
//

#ifndef BUDGET_TRACKER_HIDDENINPUT_H
#define BUDGET_TRACKER_HIDDENINPUT_H


#include <boost/predef/os.h>

#if BOOST_OS_WINDOWS
#include <windows.h>
#else

#include <termios.h>
#include <unistd.h>

#endif

class HiddenInput {
public:
    static void enable();

    static void disable();

};


#endif //BUDGET_TRACKER_HIDDENINPUT_H
