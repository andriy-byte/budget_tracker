

#ifndef BUDGET_TRACKER_DATABASEUSER_H
#define BUDGET_TRACKER_DATABASEUSER_H


#include "IDataBase.h"
#include <mutex>
#include <atomic>
#include <memory>
#include <exception>
#include <SQLiteCpp/SQLiteCpp.h>
#include "../Paths.h"
#include "../Exception.h"
#include "../Singleton.h"

template <BudgetTrackerTypes BT,typename ID>
class DataBaseUser final: public Singleton<DataBaseUser<BT, ID>>, public IDateBase, public IDataBaseService<BT>, public IDataBaseID<BT,ID> {

public:

    void connect() noexcept(false) override;

    void create() noexcept(false) override;

    void drop() noexcept(false) override;

    void update(const BT &bt) noexcept(false) override;

    void insert(const BT &bt) noexcept(false) override;

    void getAll() noexcept(false) override;

    const BT &get(const ID &id) noexcept(false) override;

    void erase(const ID &id) noexcept(false) override;

private:
    DataBaseUser()=default;
    SQLite::Database data_base;

};



#endif //BUDGET_TRACKER_DATABASEUSER_H
