//
// Created by andriy on 4/4/23.
//

#ifndef BUDGET_TRACKER_BUDGET_H
#define BUDGET_TRACKER_BUDGET_H


#include <cstddef>

class Budget {


public:
    explicit Budget(size_t user_id);

    void addMoney();

public:
    std::size_t user_id;
};


#endif //BUDGET_TRACKER_BUDGET_H
