

#include "Datetime.h"

const std::string &Datetime::getFormat() const {
    return format;
}

void Datetime::setFormat(const std::string &format) {
    this->format = format;
}

Datetime::Datetime() {
    this->setFormat("%Y-%m-%d");
}

Datetime::Datetime(const std::string &format) : format(format) {}

std::string Datetime::now() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::stringstream oss;
    oss << std::put_time(&tm, this->format.c_str());
    return oss.str();

}
