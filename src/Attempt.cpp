

#include "Attempt.h"

Attempt::Attempt(const std::size_t &attempt) : attempt(attempt), saved_attempt(attempt) {}

size_t Attempt::getAttempt() const {
    return this->attempt;
}

void Attempt::setAttempt(const std::size_t &attempt) {
    this->attempt = attempt;
}

void Attempt::reset() {
    this->attempt = this->saved_attempt;
}

Attempt &Attempt::operator++() {
    ++this->attempt;
    return *this;
}

Attempt &Attempt::operator++(int) {
    this->attempt++;
    return *this;
}

Attempt &Attempt::operator--() {
    --this->attempt;
    return *this;
}

Attempt &Attempt::operator--(int) {
    this->attempt--;
    return *this;
}

Attempt::operator bool() const {
    return this->attempt;
}

bool Attempt::isExhausted() const {
    return this->attempt == 0;
}
