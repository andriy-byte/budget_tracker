

#ifndef BUDGET_TRACKER_SQLITEDATABASECONNECTOR_H
#define BUDGET_TRACKER_SQLITEDATABASECONNECTOR_H

#include "Exception.h"
#include <sqlite_modern_cpp.h>

class SqliteDataBaseConnector {
public:
    static void connect(const std::string &filename) noexcept(false);

    static sqlite::database &get();

protected:
    SqliteDataBaseConnector() = default;

private:
    static std::unique_ptr<sqlite::database> data_base;
    static std::mutex mutex_;

};


#endif //BUDGET_TRACKER_SQLITEDATABASECONNECTOR_H
