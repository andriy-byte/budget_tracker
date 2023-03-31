

#include "SqliteDataBaseService.h"


#define SQLITE_DEFAULT_EXCEPTION \
catch (const sqlite::sqlite_exception& e) {\
std::cerr  << e.get_code() << ": " << e.what() << " during " << e.get_sql() << std::endl;\
}\


void SqliteDataBaseService<User, std::size_t>::connect() noexcept(false) {
    try {
        SqliteDataBaseConnector::connect(paths::db::app_db.string());

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<User, std::size_t>::create() noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "create table if not exist user("
                << "id integer primary key autoincrement,"
                << "name text"
                << ");";

    } SQLITE_DEFAULT_EXCEPTION

}


void SqliteDataBaseService<User, std::size_t>::drop() noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "drop table if exist user;";
    } SQLITE_DEFAULT_EXCEPTION
}


void SqliteDataBaseService<User, std::size_t>::insert(const User &bt) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "insert info user (name) VALUES (?)"
                << bt.name;


    } SQLITE_DEFAULT_EXCEPTION

}

void SqliteDataBaseService<User, std::size_t>::update(const size_t &id, const User &bt) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "update user"
                << "set"
                << "name=?"
                << "where id=?"
                << bt.name
                << id;

    } SQLITE_DEFAULT_EXCEPTION
}

const User &SqliteDataBaseService<User, std::size_t>::get(const size_t &id) noexcept(false) {
    try {
        User user;
        SqliteDataBaseConnector::get()
                << "select * from user where id =?"
                << id
                >> [&](std::size_t id_,
                       std::string name) {
                    user.id = id_;
                    user.name = std::move(name);
                };

        return user;

    } SQLITE_DEFAULT_EXCEPTION

}

void SqliteDataBaseService<User, std::size_t>::erase(const size_t &id) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "delete from user where id=?;" << id;
    } SQLITE_DEFAULT_EXCEPTION
}

std::vector<User> SqliteDataBaseService<User, std::size_t>::getAll() noexcept(false) {
    try {
        std::vector<User> users;
        SqliteDataBaseConnector::get()
                << "select * from user;"
                >> [&](std::vector<User> users_) {
                    users = std::move(users_);
                };

        return users;
    } SQLITE_DEFAULT_EXCEPTION

}

std::size_t SqliteDataBaseService<User, std::size_t>::getRowsQuantity() noexcept(false) {
    try {
        std::size_t row_quantity;
        SqliteDataBaseConnector::get()
                << "select count(*) from user;"
                >> [&](std::size_t row_quantity_) {
                    row_quantity = row_quantity_;
                };

        return row_quantity;
    } SQLITE_DEFAULT_EXCEPTION
}

std::size_t SqliteDataBaseService<User, std::size_t>::getId(const std::string& name) {
    try {
        std::size_t id;
        SqliteDataBaseConnector::get()
                << "select id from user where name=?;"
                << name
                >> [&](std::size_t id_) {
                    id = id_;
                };

        return id;
    } SQLITE_DEFAULT_EXCEPTION
}


void SqliteDataBaseService<BudgetGroup, std::size_t>::connect() noexcept(false) {
    try {
        SqliteDataBaseConnector::connect(paths::db::app_db.string());

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetGroup, std::size_t>::create() noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "create table if not exist budget_group("
                << "id integer primary key,"
                << "user_id integer"
                << ");";
    } SQLITE_DEFAULT_EXCEPTION

}

void SqliteDataBaseService<BudgetGroup, std::size_t>::drop() noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "drop table if exist budget_group;";
    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetGroup, std::size_t>::insert(const BudgetGroup &bt) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "insert into budget_group (id, user_id) values(?, ?);"
                << bt.id << bt.user_id;
    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetGroup, std::size_t>::update(const size_t &id, const BudgetGroup &bt) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "update budget_group"
                << "set"
                << "id=?"
                << "user_id=?"
                << "where id=?;"
                << bt.id
                << bt.user_id
                << id;

    } SQLITE_DEFAULT_EXCEPTION

}

const BudgetGroup &SqliteDataBaseService<BudgetGroup, std::size_t>::get(const size_t &id) noexcept(false) {
    try {
        BudgetGroup budget_group;
        SqliteDataBaseConnector::get()
                << "select * from budget_group where id=?"
                << id
                >> [&](std::size_t id_,
                       std::size_t user_id) {
                    budget_group.id = id_;
                    budget_group.user_id = user_id;
                };

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetGroup, std::size_t>::erase(const size_t &id) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "delete from budget_group where id=?;" << id;
    } SQLITE_DEFAULT_EXCEPTION
}

std::vector<BudgetGroup> SqliteDataBaseService<BudgetGroup, std::size_t>::getAll() noexcept(false) {
    try {
        std::vector<BudgetGroup> budget_groups;
        SqliteDataBaseConnector::get()
                << "select * from budget_group;"
                >> [&](std::vector<BudgetGroup> budget_groups_) {
                    budget_groups = std::move(budget_groups_);
                };

        return budget_groups;
    } SQLITE_DEFAULT_EXCEPTION

}

std::size_t SqliteDataBaseService<BudgetGroup, std::size_t>::getRowsQuantity() noexcept(false) {
    try {
        std::size_t row_quantity;
        SqliteDataBaseConnector::get()
                << "select count(*) from budget_group;"
                >> [&](std::size_t row_quantity_) {
                    row_quantity = row_quantity_;
                };

        return row_quantity;
    } SQLITE_DEFAULT_EXCEPTION
}


void SqliteDataBaseService<BudgetInfo, std::size_t>::connect() noexcept(false) {
    try {
        SqliteDataBaseConnector::connect(paths::db::app_db.string());

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetInfo, std::size_t>::create() noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "create table if not exist budget_info("
                << "id integer primary key,"
                << "money real"
                << "date_time text"
                << ");";
    } SQLITE_DEFAULT_EXCEPTION

}

void SqliteDataBaseService<BudgetInfo, std::size_t>::drop() noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "drop table if exist budget_info;";
    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetInfo, std::size_t>::insert(const BudgetInfo &bt) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "insert into budget_info (id, money, date_time) values(?, ?, ?);"
                << bt.id << bt.money << bt.date_time;

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetInfo, std::size_t>::update(const size_t &id, const BudgetInfo &bt) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "update budget_info"
                << "set"
                << "id=?"
                << "money=?"
                << "date_time=?"
                << "where id=?"
                << bt.id
                << bt.money
                << bt.date_time
                << id;

    } SQLITE_DEFAULT_EXCEPTION

}

const BudgetInfo &SqliteDataBaseService<BudgetInfo, std::size_t>::get(const size_t &id) noexcept(false) {
    try {
        BudgetInfo budget_info;
        SqliteDataBaseConnector::get()
                << "select * from budget_info where id=?"
                << id
                >> [&](std::size_t id_,
                       double money,
                       std::string date_time) {
                    budget_info.id = id_;
                    budget_info.money = money;
                    budget_info.date_time = std::move(date_time);
                };
        return budget_info;
    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetInfo, std::size_t>::erase(const size_t &id) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "delete from budget_info where id=?;" << id;
    } SQLITE_DEFAULT_EXCEPTION
}

std::vector<BudgetInfo> SqliteDataBaseService<BudgetInfo, std::size_t>::getAll() noexcept(false) {
    try {
        std::vector<BudgetInfo> budget_infos;
        SqliteDataBaseConnector::get()
                << "select * from budget_info;"
                >> [&](std::vector<BudgetInfo> budget_infos_) {
                    budget_infos = std::move(budget_infos_);
                };

        return budget_infos;
    } SQLITE_DEFAULT_EXCEPTION

}

std::size_t SqliteDataBaseService<BudgetInfo, std::size_t>::getRowsQuantity() noexcept(false) {
    try {
        std::size_t row_quantity;
        SqliteDataBaseConnector::get()
                << "select count(*) from budget_info;"
                >> [&](std::size_t row_quantity_) {
                    row_quantity = row_quantity_;
                };

        return row_quantity;
    } SQLITE_DEFAULT_EXCEPTION
}


void SqliteDataBaseService<Permission, std::size_t>::connect() noexcept(false) {
    try {
        SqliteDataBaseConnector::connect(paths::db::app_db.string());

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<Permission, std::size_t>::create() noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "create table if not exist permission("
                << "user_id integer,"
                << "password text"
                << ");";
    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<Permission, std::size_t>::drop() noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "drop table if exist permission;";
    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<Permission, std::size_t>::insert(const Permission &bt) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "insert into permission (user_id, password) values(?, ?);"
                << bt.user_id
                << bt.password;

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<Permission, std::size_t>::update(const size_t &id, const Permission &bt) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "update permission "
                << "set"
                << "user_id=?"
                << "password=?"
                << "where user_id=?;"
                << bt.user_id
                << bt.password
                << id;

    } SQLITE_DEFAULT_EXCEPTION
}

const Permission &SqliteDataBaseService<Permission, std::size_t>::get(const size_t &id) noexcept(false) {
    try {
        Permission permission;
        SqliteDataBaseConnector::get()
                << "select * from permission where user_id=?;"
                << id
                >> [&](std::size_t user_id, std::string password) {
                    permission.user_id = user_id;
                    permission.password = std::move(password);
                };
        return permission;
    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<Permission, std::size_t>::erase(const size_t &id) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "delete from user_name where id=?;" << id;
    } SQLITE_DEFAULT_EXCEPTION
}

std::vector<Permission> SqliteDataBaseService<Permission, std::size_t>::getAll() noexcept(false) {
    try {
        std::vector<Permission> permissions;
        SqliteDataBaseConnector::get()
                << "select * from permission;"
                >> [&](std::vector<Permission> permissions_) {
                    permissions = std::move(permissions_);
                };

        return permissions;
    } SQLITE_DEFAULT_EXCEPTION
}

std::size_t SqliteDataBaseService<Permission, std::size_t>::getRowsQuantity() noexcept(false) {
    try {
        std::size_t row_quantity;
        SqliteDataBaseConnector::get()
                << "select count(*) from permission;"
                >> [&](std::size_t row_quantity_) {
                    row_quantity = row_quantity_;
                };

        return row_quantity;
    } SQLITE_DEFAULT_EXCEPTION
}