

#ifndef BUDGET_TRACKER_SESSION_H
#define BUDGET_TRACKER_SESSION_H


#include "Commands.h"
#include "PasswordInput.h"
#include "Authentication.h"
#include "Attempt.h"
#include "Datetime.h"
#include <string_interpolation.h>
#include <memory>
#include <fmt/color.h>
#include <fmt/printf.h>
#include <functional>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/algorithm/string.hpp>

namespace session_info {
    const extern std::string help;
    const extern std::string input_line;
    const extern std::string start_message;
}

class Session {
public:
    static void run();
};


#endif //BUDGET_TRACKER_SESSION_H
