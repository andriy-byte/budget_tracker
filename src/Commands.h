
#ifndef BUDGET_TRACKER_COMMANDS_H
#define BUDGET_TRACKER_COMMANDS_H


#include <boost/regex.hpp>


namespace commands {
    const extern boost::regex sign_in;
    const extern boost::regex sign_up;
    const extern boost::regex income;
    const extern boost::regex costs;
    const extern boost::regex show;
    const extern boost::regex report;
    const extern boost::regex exit;
    const extern boost::regex help;

}


#endif //BUDGET_TRACKER_COMMANDS_H
