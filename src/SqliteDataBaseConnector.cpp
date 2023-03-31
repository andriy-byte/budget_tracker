

#include "SqliteDataBaseConnector.h"


std::unique_ptr<sqlite::database> SqliteDataBaseConnector::data_base{nullptr};

std::mutex SqliteDataBaseConnector::mutex_;

void SqliteDataBaseConnector::connect(const std::string &filename) noexcept(false) {
    std::lock_guard<std::mutex> lock{mutex_};
    try {
        data_base = std::make_unique<sqlite::database>(filename);
    } catch (Exception &e) {
        std::cerr << e.what();
    }
}

sqlite::database &SqliteDataBaseConnector::get() {
    std::lock_guard<std::mutex> lock{mutex_};
    return *data_base;
}
