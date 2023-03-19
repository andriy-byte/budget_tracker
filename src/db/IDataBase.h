

#ifndef BUDGET_TRACKER_IDATABASE_H
#define BUDGET_TRACKER_IDATABASE_H


#include "DatabaseTables.h"
#include <concepts>


struct IDateBase{
    virtual void connect() noexcept(false) = 0;
    virtual void create() noexcept(false) = 0;
    virtual void drop() noexcept(false) = 0;


};



template<typename T>
concept BudgetTrackerTypes = std::is_same<T, BudgetInfo>::value
                             || std::is_same<T, BudgetGroup>::value
                             || std::is_same<T, User>::value;

template<BudgetTrackerTypes BT>
struct IDataBaseService {
    virtual void update(const BT&) noexcept(false) = 0 ;
    virtual void insert(const BT&) noexcept(false) = 0;
    virtual void getAll() noexcept(false) = 0;

};

template <BudgetTrackerTypes BT, typename ID>
struct IDataBaseID{
    virtual const BT& get(const ID&) noexcept(false) = 0;
    virtual void erase(const ID&) noexcept(false) = 0;

};



#endif //BUDGET_TRACKER_IDATABASE_H
