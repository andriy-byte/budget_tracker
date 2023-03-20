

#ifndef BUDGET_TRACKER_IDATABASE_H
#define BUDGET_TRACKER_IDATABASE_H


#include "DatabaseTables.h"
#include <concepts>
#include <vector>

struct IDateBaseService{
    virtual void connect() noexcept(false) = 0;
    virtual void create() noexcept(false) = 0;
    virtual void drop() noexcept(false) = 0;
};



template<typename T>
concept BudgetTrackerTypes = std::is_same<T, BudgetInfo>::value
                             || std::is_same<T, BudgetGroup>::value
                             || std::is_same<T, User>::value
                             || std::is_same<T, Permission>::value;

template<BudgetTrackerTypes BT>
struct IDataBaseModificate {
    virtual void insert(const BT&) noexcept(false) = 0;
};

template <BudgetTrackerTypes BT, typename ID>
struct IDataBaseSelectID{
    virtual void update(const ID&, const BT&) noexcept(false) = 0 ;
    virtual const BT& get(const ID&) noexcept(false) = 0;
    virtual void erase(const ID&) noexcept(false) = 0;
};

template<BudgetTrackerTypes BT>
struct IDateBaseSelect{
    virtual std::vector<BT> getAll() noexcept(false) = 0;
    virtual std::size_t getRowsQuantity() noexcept(false) = 0;
};


#endif //BUDGET_TRACKER_IDATABASE_H