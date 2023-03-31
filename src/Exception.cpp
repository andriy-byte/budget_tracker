

#include "Exception.h"


Exception::Exception(const boost::source_location &location)
        : location(location) {}

std::string Exception::what() {
    this->initializeBasicInformMessage();
    return this->informMessage.getSubstituted();
}

const boost::source_location &Exception::getLocation() const noexcept {
    return this->location;
}

const istr::StringInterpolation &Exception::getExceptionMessage() const noexcept {
    return this->exceptionMessage;
}

void Exception::setLocation(
        const boost::source_location &location) noexcept {
    this->location = location;
}

void Exception::setExceptionMessage(
        const istr::StringInterpolation &exceptionMessage) noexcept {
    this->exceptionMessage = exceptionMessage;
}

Exception::Exception(istr::StringInterpolation exceptionMessage)
        : exceptionMessage(std::move(exceptionMessage)) {}

Exception::Exception(const boost::source_location &location,
                     istr::StringInterpolation exceptionMessage)
        : location(location), exceptionMessage(std::move(exceptionMessage)) {}

Exception::Exception() {
    setExceptionMessage(
            istr::StringInterpolation("throwing a base exception, look at the information above"));
}

void Exception::initializeBasicInformMessage() {
    this->informMessage = istr::StringInterpolation("\n"
                                                    "exception in file : {{file_name}}\n"
                                                    "inside function : {{function_name}}\n"
                                                    "at line : {{line}}\n"
                                                    "exception message : {{exception_message}}\n");
    this->informMessage.putPatternArguments({{"file_name",         getLocation().file_name()},
                                             {"function_name",     getLocation().function_name()},
                                             {"line",              std::to_string(getLocation().line())},
                                             {"exception_message", exceptionMessage.getSubstituted()}});
}
