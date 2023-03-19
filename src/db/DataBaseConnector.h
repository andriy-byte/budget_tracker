

#ifndef BUDGET_TRACKER_DATABASECONNECTOR_H
#define BUDGET_TRACKER_DATABASECONNECTOR_H


#include "../Singleton.h"
#include "../Exception.h"
#include <SQLiteCpp/SQLiteCpp.h>

class DataBaseConnector : Singleton<DataBaseConnector> {
    void connect(const std::string& filename, int flags) noexcept(false);
    const SQLite::Database & get();
private:
    SQLite::Database data_base;
};


#endif //BUDGET_TRACKER_DATABASECONNECTOR_H
