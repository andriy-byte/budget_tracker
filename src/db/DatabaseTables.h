

#ifndef BUDGET_TRACKER_DATABASETABLES_H
#define BUDGET_TRACKER_DATABASETABLES_H



#include<string>

struct User{
    std::size_t id;
    std::string full_name;
    std::string nick_name;
    std::string password;

};

struct BudgetGroup{
    std::size_t id;
    std::size_t user_id;
};

struct BudgetInfo{
    std::size_t id;
    std::string last_update;

};


#endif //BUDGET_TRACKER_DATABASETABLES_H