

#ifndef BUDGET_TRACKER_SQLITEDATABASESERVICE_H
#define BUDGET_TRACKER_SQLITEDATABASESERVICE_H


#include "IDataBase.h"
#include <mutex>
#include <atomic>
#include <memory>
#include <exception>
#include <SQLiteCpp/SQLiteCpp.h>
#include "../Paths.h"
#include "../Exception.h"
#include "../Singleton.h"
#include "SqliteDataBaseConnector.h"

template <BudgetTrackerTypes BT,typename ID>
class SqliteDataBaseService final: public Singleton<SqliteDataBaseService<BT, ID>>,
                                   public IDateBaseService,
                                   public IDataBaseModificate<BT>,
                                   public IDataBaseSelectID<BT,ID>,
                                   public IDateBaseSelect<BT>{

public:
/*
    void connect() noexcept(false) override;
    void create() noexcept(false) override;
    void drop() noexcept(false) override;
    void insert(const BT &bt) noexcept(false) override;
    void update(const ID &id, const BT &bt) noexcept(false) override;
    const BT &get(const ID &id) noexcept(false) override;
    void erase(const ID &id) noexcept(false) override;
    std::vector<BT> getAll() noexcept(false) override;
    std::size_t getRowsQuantity() noexcept(false) override;
*/
private:
    SqliteDataBaseService()=default;

};

template <>
class SqliteDataBaseService <User,std::size_t> final: public Singleton<SqliteDataBaseService<User, std::size_t>>,
                                   public IDateBaseService,
                                   public IDataBaseModificate<User>,
                                   public IDataBaseSelectID<User,std::size_t>,
                                   public IDateBaseSelect<User>{

public:
    void connect() noexcept(false) override;
    void create() noexcept(false) override;
    void drop() noexcept(false) override;
    void insert(const User &bt) noexcept(false) override;
    void update(const size_t &id, const User &bt) noexcept(false) override;
    const User &get(const size_t &id) noexcept(false) override;
    void erase(const size_t &id) noexcept(false) override;
    std::vector<User> getAll() noexcept(false) override;
    std::size_t getRowsQuantity() noexcept(false) override;
private:
    SqliteDataBaseService()=default;

};

template <>
class SqliteDataBaseService <BudgetGroup,std::size_t> final: public Singleton<SqliteDataBaseService<BudgetGroup, std::size_t>>,
                                                      public IDateBaseService,
                                                      public IDataBaseModificate<BudgetGroup>,
                                                      public IDataBaseSelectID<BudgetGroup,std::size_t>,
                                                      public IDateBaseSelect<BudgetGroup>{

public:
    void connect() noexcept(false) override;
    void create() noexcept(false) override;
    void drop() noexcept(false) override;
    void insert(const BudgetGroup &bt) noexcept(false) override;
    void update(const size_t &id, const BudgetGroup &bt) noexcept(false) override;
    const BudgetGroup &get(const size_t &id) noexcept(false) override;
    void erase(const size_t &id) noexcept(false) override;
    std::vector<BudgetGroup> getAll() noexcept(false) override;
    std::size_t getRowsQuantity() noexcept(false) override;

private:
    SqliteDataBaseService()=default;

};

template <>
class SqliteDataBaseService <BudgetInfo,std::size_t> final: public Singleton<SqliteDataBaseService<BudgetInfo, std::size_t>>,
                                                             public IDateBaseService,
                                                             public IDataBaseModificate<BudgetInfo>,
                                                             public IDataBaseSelectID<BudgetInfo,std::size_t>,
                                                             public IDateBaseSelect<BudgetInfo>{

public:
    void connect() noexcept(false) override;
    void create() noexcept(false) override;
    void drop() noexcept(false) override;
    void insert(const BudgetInfo &bt) noexcept(false) override;
    void update(const size_t &id, const BudgetInfo &bt) noexcept(false) override;
    const BudgetInfo &get(const size_t &id) noexcept(false) override;
    void erase(const size_t &id) noexcept(false) override;
    std::vector<BudgetInfo> getAll() noexcept(false) override;
    std::size_t getRowsQuantity() noexcept(false) override;

private:
    SqliteDataBaseService()=default;

};

template <>
class SqliteDataBaseService <Permission,std::size_t> final: public Singleton<SqliteDataBaseService<Permission, std::size_t>>,
                                                            public IDateBaseService,
                                                            public IDataBaseModificate<Permission>,
                                                            public IDataBaseSelectID<Permission,std::size_t>,
                                                            public IDateBaseSelect<Permission>{

public:
    void connect() noexcept(false) override;
    void create() noexcept(false) override;
    void drop() noexcept(false) override;
    void insert(const Permission &bt) noexcept(false) override;
    void update(const size_t &id, const Permission &bt) noexcept(false) override;
    const Permission &get(const size_t &id) noexcept(false) override;
    void erase(const size_t &id) noexcept(false) override;
    std::vector<Permission> getAll() noexcept(false) override;
    std::size_t getRowsQuantity() noexcept(false) override;

private:
    SqliteDataBaseService()=default;

};

#endif //BUDGET_TRACKER_SQLITEDATABASESERVICE_H