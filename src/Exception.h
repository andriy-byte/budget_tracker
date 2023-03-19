

#ifndef BUDGET_TRACKER_EXCEPTION_H
#define BUDGET_TRACKER_EXCEPTION_H


#include <exception>
#include <string_interpolation.h>
#include <boost/assert/source_location.hpp>
#include <sstream>
#include <string>

class Exception : public std::exception {

public:
    explicit Exception(const boost::source_location &location);

    explicit Exception(istr::StringInterpolation exceptionMessage);

    virtual std::string what();

    Exception(const boost::source_location &location,
                 istr::StringInterpolation exceptionMessage);

    Exception();

    [[nodiscard]] const boost::source_location & getLocation() const noexcept;

    [[nodiscard]] const istr::StringInterpolation &getExceptionMessage() const noexcept;

    void setLocation(const boost::source_location &location) noexcept;

    void setExceptionMessage(const istr::StringInterpolation &exceptionMessage) noexcept;

protected:

    virtual void initializeBasicInformMessage();


    boost::source_location location;
    istr::StringInterpolation exceptionMessage;
    istr::StringInterpolation informMessage;
};

#endif //BUDGET_TRACKER_EXCEPTION_H
