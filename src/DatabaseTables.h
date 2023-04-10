

#ifndef BUDGET_TRACKER_DATABASETABLES_H
#define BUDGET_TRACKER_DATABASETABLES_H


#include<string>

struct User {
    std::size_t id;
    std::string name;

};

struct BudgetGroup {
    std::size_t id;
    std::size_t user_id;
};

struct BudgetInfo {
    std::size_t id;
    double money;
    std::string date_time;
};

struct Permission {
    std::size_t user_id;
    std::string password;

};

#endif //BUDGET_TRACKER_DATABASETABLES_Hcd