

#include "DataBaseConnector.h"

void DataBaseConnector::connect(const std::string &filename, int flags ) noexcept(false) {
    try{
        this->data_base = SQLite::Database(filename,flags);
    }catch (Exception &e){
        std::cerr << e.what();
    }
}

const SQLite::Database &DataBaseConnector::get() {
    return this->data_base;
}
