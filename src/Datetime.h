

#ifndef BUDGET_TRACKER_DATETIME_H
#define BUDGET_TRACKER_DATETIME_H


#include <string>
#include <iomanip>
#include <sstream>

class Datetime {

public:
    std::string now();

    Datetime();

    explicit Datetime(const std::string &format);

    const std::string &getFormat() const;

    void setFormat(const std::string &format);

private:
    std::string format;

};


#endif //BUDGET_TRACKER_DATETIME_H
