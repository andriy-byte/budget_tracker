

#ifndef BUDGET_TRACKER_SQLITEDATABASESERVICE_H
#define BUDGET_TRACKER_SQLITEDATABASESERVICE_H


#include "IDataBase.h"
#include <mutex>
#include <memory>
#include <exception>
#include <boost/assert/source_location.hpp>
#include "Exception.h"
#include "Singleton.h"
#include "SqliteDataBaseConnector.h"

template<BudgetTrackerTypes BT, typename ID>
class SqliteDataBaseService final : public Singleton<SqliteDataBaseService<BT, ID>>,
                                    public IDateBaseService,
                                    public IDataBaseModificate<BT>,
                                    public IDataBaseID<BT, ID>,
                                    public IDateBaseSelect<BT> {

protected:
    SqliteDataBaseService() = default;

};

template<>
class SqliteDataBaseService<User, std::size_t> final : public Singleton<SqliteDataBaseService<User, std::size_t>>,
                                                       public IDateBaseService,
                                                       public IDataBaseModificate<User>,
                                                       public IDataBaseID<User, std::size_t>,
                                                       public IDateBaseSelect<User> {

public:
    void connect() noexcept(false) override;

    void create() noexcept(false) override;

    void drop() noexcept(false) override;

    void insert(const User &bt) noexcept(false) override;

    void update(const size_t &id, const User &bt) noexcept(false) override;

    User get(const size_t &id) noexcept(false) override;

    void erase(const size_t &id) noexcept(false) override;

    bool exists(const size_t &id) noexcept(false) override;

    bool exists(const User &bt) noexcept(false) override;

    std::vector<User> getAll() noexcept(false) override;

    std::size_t getRowsQuantity() noexcept(false) override;

    std::size_t getId(const std::string &name) noexcept(false);

    bool existsByName(const std::string &name) noexcept(false);

    std::vector<User> getAll(const size_t &id) noexcept(false) override;

    SqliteDataBaseService() = default;


};

template<>
class SqliteDataBaseService<BudgetGroup, std::size_t> final
        : public Singleton<SqliteDataBaseService<BudgetGroup, std::size_t>>,
          public IDateBaseService,
          public IDataBaseModificate<BudgetGroup>,
          public IDataBaseID<BudgetGroup, std::size_t>,
          public IDateBaseSelect<BudgetGroup> {

public:
    void connect() noexcept(false) override;

    void create() noexcept(false) override;

    bool exists(const size_t &id) noexcept(false) override;

    bool exists(const BudgetGroup &bt) noexcept(false) override;

    void drop() noexcept(false) override;

    void insert(const BudgetGroup &bt) noexcept(false) override;

    void update(const size_t &id, const BudgetGroup &bt) noexcept(false) override;

    BudgetGroup get(const size_t &id) noexcept(false) override;

    void erase(const size_t &id) noexcept(false) override;

    std::vector<BudgetGroup> getAll() noexcept(false) override;

    std::size_t getRowsQuantity() noexcept(false) override;

    std::vector<BudgetGroup> getAll(const size_t &id) noexcept(false) override;

    SqliteDataBaseService() = default;

};

template<>
class SqliteDataBaseService<BudgetInfo, std::size_t> final
        : public Singleton<SqliteDataBaseService<BudgetInfo, std::size_t>>,
          public IDateBaseService,
          public IDataBaseModificate<BudgetInfo>,
          public IDataBaseID<BudgetInfo, std::size_t>,
          public IDateBaseSelect<BudgetInfo> {

public:
    void connect() noexcept(false) override;

    void create() noexcept(false) override;

    void drop() noexcept(false) override;

    bool exists(const size_t &id) noexcept(false) override;

    bool exists(const BudgetInfo &bt) noexcept(false) override;

    void insert(const BudgetInfo &bt) noexcept(false) override;

    void update(const size_t &id, const BudgetInfo &bt) noexcept(false) override;

    BudgetInfo get(const size_t &id) noexcept(false) override;

    void erase(const size_t &id) noexcept(false) override;

    std::vector<BudgetInfo> getAll() noexcept(false) override;

    std::size_t getRowsQuantity() noexcept(false) override;

    std::vector<BudgetInfo> getAll(const size_t &id) noexcept(false) override;

    SqliteDataBaseService() = default;

};

template<>
class SqliteDataBaseService<Permission, std::size_t> final
        : public Singleton<SqliteDataBaseService<Permission, std::size_t>>,
          public IDateBaseService,
          public IDataBaseModificate<Permission>,
          public IDataBaseID<Permission, std::size_t>,
          public IDateBaseSelect<Permission> {

public:
    void connect() noexcept(false) override;

    void create() noexcept(false) override;

    void drop() noexcept(false) override;

    void insert(const Permission &bt) noexcept(false) override;

    void update(const size_t &id, const Permission &bt) noexcept(false) override;

    Permission get(const size_t &id) noexcept(false) override;

    void erase(const size_t &id) noexcept(false) override;

    std::vector<Permission> getAll() noexcept(false) override;

    std::size_t getRowsQuantity() noexcept(false) override;

    std::vector<Permission> getAll(const size_t &id) noexcept(false) override;

    bool exists(const size_t &id) noexcept(false) override;

    bool exists(const Permission &bt) noexcept(false) override;

    SqliteDataBaseService() = default;

};

#endif //BUDGET_TRACKER_SQLITEDATABASESERVICE_H