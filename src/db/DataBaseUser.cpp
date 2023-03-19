

#include "DataBaseUser.h"



template<BudgetTrackerTypes BT, typename ID>
void DataBaseUser<BT, ID>::connect() noexcept(false) {
    this->data_base = SQLite::Database{paths::db::app_db.string(), SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE};
}

template<BudgetTrackerTypes BT, typename ID>
void DataBaseUser<BT, ID>::create() noexcept(false) {

}

template<BudgetTrackerTypes BT, typename ID>
void DataBaseUser<BT, ID>::drop() noexcept(false) {

}

template<BudgetTrackerTypes BT, typename ID>
void DataBaseUser<BT, ID>::update(const BT &bt) noexcept(false) {

}

template<BudgetTrackerTypes BT, typename ID>
void DataBaseUser<BT, ID>::insert(const BT &bt) noexcept(false) {

}

template<BudgetTrackerTypes BT, typename ID>
void DataBaseUser<BT, ID>::getAll() noexcept(false) {

}

template<BudgetTrackerTypes BT, typename ID>
const BT &DataBaseUser<BT, ID>::get(const ID &id) noexcept(false) {
    return <#initializer#>;
}

template<BudgetTrackerTypes BT, typename ID>
void DataBaseUser<BT, ID>::erase(const ID &id) noexcept(false) {

}


