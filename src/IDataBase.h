

#ifndef BUDGET_TRACKER_IDATABASE_H
#define BUDGET_TRACKER_IDATABASE_H


#include "DatabaseTables.h"
#include <concepts>
#include <vector>

struct IDateBaseService {
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
    virtual void insert(const BT &) noexcept(false) = 0;
};

template<BudgetTrackerTypes BT, typename ID>
struct IDataBaseID {
    virtual void update(const ID &, const BT &) noexcept(false) = 0;

    virtual BT get(const ID &) noexcept(false) = 0;

    virtual std::vector<BT> getAll(const ID &) noexcept(false) = 0;

    virtual void erase(const ID &) noexcept(false) = 0;

    virtual bool exists(const ID &) noexcept(false) = 0;
};


template<BudgetTrackerTypes BT>
struct IDateBaseSelect {
    virtual std::vector<BT> getAll() noexcept(false) = 0;

    virtual bool exists(const BT &) noexcept(false) = 0;

    virtual std::size_t getRowsQuantity() noexcept(false) = 0;
};


#endif //BUDGET_TRACKER_IDATABASE_H