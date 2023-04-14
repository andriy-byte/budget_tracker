

#include "SqliteDataBaseService.h"


#define SQLITE_DEFAULT_EXCEPTION \
catch (const sqlite::sqlite_exception& e) { \
boost::source_location current_location;                                 \
std::cerr << e.get_code() << ": " << e.what() << " during " << e.get_sql() << std::endl; \
std::cerr << "in file : " << current_location.file_name() << " at line : " << current_location.line() << " in function : " << current_location.function_name(); \
}\


void SqliteDataBaseService<User, std::size_t>::connect() noexcept(false) {
    try {
        SqliteDataBaseConnector::connect("budget_tracker.sqlite");

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<User, std::size_t>::create() noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "create table if not exists user("
                   "id_ integer primary key autoincrement,"
                   "name text"
                   ");";

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
                << "insert into user (name) values (?);"
                << bt.name;


    } SQLITE_DEFAULT_EXCEPTION

}

void SqliteDataBaseService<User, std::size_t>::update(const size_t &id, const User &bt) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "update user"
                   "set"
                   "name=?"
                   "where id_ =?;"
                << bt.name
                << id;

    } SQLITE_DEFAULT_EXCEPTION
}

User SqliteDataBaseService<User, std::size_t>::get(const size_t &id) noexcept(false) {
    try {
        User user;
        SqliteDataBaseConnector::get()
                << "select * from user where id_ =? order by rowid desc limit 1;"
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
                << "delete from user where id_ =?;" << id;
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
                >> row_quantity;

        return row_quantity;
    } SQLITE_DEFAULT_EXCEPTION
}

std::size_t SqliteDataBaseService<User, std::size_t>::getId(const std::string &name) noexcept(false) {
    try {
        std::size_t id;
        SqliteDataBaseConnector::get()
                << "select id_ from user where name=?;"
                << name
                >> id;
        return id;
    } SQLITE_DEFAULT_EXCEPTION
}

std::vector<User> SqliteDataBaseService<User, std::size_t>::getAll(const size_t &id) noexcept(false) {
    try {
        std::vector<User> users;
        SqliteDataBaseConnector::get()
                << "select * from user where id_ = ?;" << id
                >> [&](std::vector<User> users_) {
                    users = std::move(users_);
                };

        return users;
    } SQLITE_DEFAULT_EXCEPTION
}

bool SqliteDataBaseService<User, std::size_t>::exists(const size_t &id) noexcept(false) {
    try {
        bool exists;
        SqliteDataBaseConnector::get()
                << "select exists(select * from user where id_ =?);" << id
                >> exists;

        return exists;

    } SQLITE_DEFAULT_EXCEPTION
}

bool SqliteDataBaseService<User, std::size_t>::exists(const User &bt) noexcept(false) {
    try {
        bool exists;
        SqliteDataBaseConnector::get()
                << "select exists(select * from user where id_ =? and name=?);" << bt.id << bt.name
                >> exists;

        return exists;

    } SQLITE_DEFAULT_EXCEPTION
}

bool SqliteDataBaseService<User, std::size_t>::existsByName(const std::string &name) noexcept(false) {
    try {
        bool exists;
        SqliteDataBaseConnector::get()
                << "select exists(select * from user where name=?);" << name
                >> exists;

        return exists;

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetGroup, std::size_t>::connect() noexcept(false) {
    try {
        SqliteDataBaseConnector::connect("budget_tracker.sqlite");

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetGroup, std::size_t>::create() noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "create table if not exists budget_group("
                   "id_ integer primary key,"
                   "user_id integer"
                   ");";
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
                << "insert into budget_group (id_,user_id) values(?,?);"
                << bt.id << bt.user_id;
    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetGroup, std::size_t>::update(const size_t &id, const BudgetGroup &bt) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "update budget_group"
                   "set"
                   "id_ =?"
                   "user_id=?"
                   "where id_ =?;"
                << bt.id
                << bt.user_id
                << id;

    } SQLITE_DEFAULT_EXCEPTION

}

bool SqliteDataBaseService<BudgetGroup, std::size_t>::exists(const size_t &id) noexcept(false) {
    try {
        bool exists;
        SqliteDataBaseConnector::get()
                << "select exists(select * from budget_group where id_ =?);"
                << id >> exists;

        return exists;

    } SQLITE_DEFAULT_EXCEPTION
}

bool SqliteDataBaseService<BudgetGroup, std::size_t>::exists(const BudgetGroup &bt) noexcept(false) {
    try {
        bool exists;
        SqliteDataBaseConnector::get()
                << "select exists(select * from budget_group where id_ =? user_id=?);"
                << bt.id << bt.user_id >> exists;

        return exists;

    } SQLITE_DEFAULT_EXCEPTION
}


BudgetGroup SqliteDataBaseService<BudgetGroup, std::size_t>::get(const size_t &id) noexcept(false) {
    try {
        BudgetGroup budget_group;
        SqliteDataBaseConnector::get()
                << "select * from budget_group where id_ =? order by rowid desc limit 1;"
                << id
                >> [&](std::size_t id_,
                       std::size_t user_id) {
                    budget_group.id = id_;
                    budget_group.user_id = user_id;
                };
        return budget_group;
    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetGroup, std::size_t>::erase(const size_t &id) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "delete from budget_group where id_ =?;" << id;
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
                >> row_quantity;

        return row_quantity;
    } SQLITE_DEFAULT_EXCEPTION
}

std::vector<BudgetGroup> SqliteDataBaseService<BudgetGroup, std::size_t>::getAll(const size_t &id) noexcept(false) {
    try {
        std::vector<BudgetGroup> budget_groups;
        SqliteDataBaseConnector::get()
                << "select * from budget_group where id_ =?;" << id
                >> [&](std::vector<BudgetGroup> budget_groups_) {
                    budget_groups = std::move(budget_groups_);
                };

        return budget_groups;
    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetInfo, std::size_t>::connect() noexcept(false) {
    try {
        SqliteDataBaseConnector::connect("budget_tracker.sqlite");

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetInfo, std::size_t>::create() noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "create table if not exists budget_info("
                   "id_ integer,"
                   "money real,"
                   "date_time text"
                   ");";
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
                << "insert into budget_info (id_,money,date_time) values(?,?,?);"
                << bt.id << bt.money << bt.date_time;

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<BudgetInfo, std::size_t>::update(const size_t &id, const BudgetInfo &bt) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "update budget_info"
                   "set"
                   "id_ =?"
                   "money=?"
                   "date_time=?"
                   "where id_ =?;"
                << bt.id
                << bt.money
                << bt.date_time
                << id;

    } SQLITE_DEFAULT_EXCEPTION

}

std::vector<BudgetInfo> SqliteDataBaseService<BudgetInfo, std::size_t>::getBetweenDatesById(const std::size_t &id,
                                                                                            const std::string &from,
                                                                                            const std::string &to) noexcept(false) {
    try {
        std::vector<BudgetInfo> budget_infos;
        SqliteDataBaseConnector::get()
                << "select * from budget_info where id_ =? and date(date_time) >= date(?) and date(date_time) <= date(?);"
                << id
                << from
                << to
                >> [&](std::vector<BudgetInfo> budget_infos_) {
                    budget_infos = std::move(budget_infos_);
                };

        return budget_infos;
    } SQLITE_DEFAULT_EXCEPTION
}

bool SqliteDataBaseService<BudgetInfo, std::size_t>::exists(const size_t &id) noexcept(false) {
    try {
        bool exists;
        SqliteDataBaseConnector::get()
                << "select exists(select * from budget_info where id_ =?);"
                << id >> exists;

        return exists;

    } SQLITE_DEFAULT_EXCEPTION
}

bool SqliteDataBaseService<BudgetInfo, std::size_t>::exists(const BudgetInfo &bt) noexcept(false) {
    try {
        bool exists;
        SqliteDataBaseConnector::get()
                << "select exists(select * from budget_info where id_ =? and money=? and date_time=?);"
                << bt.id << bt.money << bt.date_time >> exists;

        return exists;

    } SQLITE_DEFAULT_EXCEPTION
}

bool
SqliteDataBaseService<BudgetInfo, std::size_t>::existsBetweenDatesById(const std::size_t &id, const std::string &from,
                                                                       const std::string &to) noexcept(false) {
    try {
        bool exists;
        SqliteDataBaseConnector::get()
                << "select exists(select * from budget_info where id_ =? and date(date_time) >= date(?) and date(date_time) <= date(?);"
                << id << from << to >> exists;

        return exists;

    } SQLITE_DEFAULT_EXCEPTION
}

BudgetInfo SqliteDataBaseService<BudgetInfo, std::size_t>::get(const size_t &id) noexcept(false) {
    try {
        BudgetInfo budget_info;
        SqliteDataBaseConnector::get()
                << "select * from budget_info where id_ =? order by rowid desc limit 1;"
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
                << "delete from budget_info where id_ =?;" << id;
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
                >> row_quantity;

        return row_quantity;
    } SQLITE_DEFAULT_EXCEPTION
}

std::vector<BudgetInfo> SqliteDataBaseService<BudgetInfo, std::size_t>::getAll(const size_t &id) noexcept(false) {
    try {
        std::vector<BudgetInfo> budget_infos;
        SqliteDataBaseConnector::get()
                << "select * from budget_info;"
                >> [&](std::vector<BudgetInfo> budget_info_) {
                    budget_infos = std::move(budget_info_);
                };

        return budget_infos;
    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<Permission, std::size_t>::connect() noexcept(false) {
    try {
        SqliteDataBaseConnector::connect("budget_tracker.sqlite");

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<Permission, std::size_t>::create() noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "create table if not exists permission("
                   "user_id integer,"
                   "password text"
                   ");";
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
                << "insert into permission (user_id,password) values(?,?);"
                << bt.user_id
                << bt.password;

    } SQLITE_DEFAULT_EXCEPTION
}

void SqliteDataBaseService<Permission, std::size_t>::update(const size_t &id, const Permission &bt) noexcept(false) {
    try {
        SqliteDataBaseConnector::get()
                << "update permission "
                   "set"
                   "user_id=?"
                   "password=?"
                   "where user_id=?;"
                << bt.user_id
                << bt.password
                << id;

    } SQLITE_DEFAULT_EXCEPTION
}

bool SqliteDataBaseService<Permission, std::size_t>::exists(const size_t &id) noexcept(false) {
    try {
        bool exists;
        SqliteDataBaseConnector::get()
                << "select exists(select * from permission where user_id=?);"
                << id >> exists;

        return exists;

    } SQLITE_DEFAULT_EXCEPTION
}

bool SqliteDataBaseService<Permission, std::size_t>::exists(const Permission &bt) noexcept(false) {
    try {
        bool exists;
        SqliteDataBaseConnector::get()
                << "select exists(select * from permission where user_id=? and password=?);"
                << bt.user_id << bt.password >> exists;

        return exists;

    } SQLITE_DEFAULT_EXCEPTION
}

std::vector<Permission> SqliteDataBaseService<Permission, std::size_t>::getAll(const size_t &id) noexcept(false) {
    try {
        std::vector<Permission> permissions;
        SqliteDataBaseConnector::get()
                << "select * from permission where user_id=?;" << id
                >> [&](std::vector<Permission> permissions_) {
                    permissions = std::move(permissions_);
                };

        return permissions;
    } SQLITE_DEFAULT_EXCEPTION
}

Permission SqliteDataBaseService<Permission, std::size_t>::get(const size_t &id) noexcept(false) {
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
                << "delete from user_name where id_ =?;" << id;
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
                >> row_quantity;

        return row_quantity;
    } SQLITE_DEFAULT_EXCEPTION
}