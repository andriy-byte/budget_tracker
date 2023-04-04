//
// Created by andriy on 4/4/23.
//

#ifndef BUDGET_TRACKER_ATTEMPT_H
#define BUDGET_TRACKER_ATTEMPT_H


#include <cstddef>

class Attempt {

public:
    explicit Attempt(const std::size_t &attempt);

    void reset();

    Attempt &operator++();

    Attempt &operator--();

    Attempt &operator++(int);

    Attempt &operator--(int);

    operator bool() const;

    bool isExhausted() const;

    [[nodiscard]] std::size_t getAttempt() const;

    void setAttempt(const std::size_t &attempt);

private:
    std::size_t attempt, saved_attempt;
};


#endif //BUDGET_TRACKER_ATTEMPT_H
