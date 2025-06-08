#ifndef DATABASE_H
#define DATABASE_H

#include "Table.h"
#include <unordered_map>
#include <string>

namespace dbms {

class Database {
public:
    Database(const std::string& name);
    bool createTable(const std::string& name, const Schema& schema);
    bool dropTable(const std::string& name);
    Table* getTable(const std::string& name);

    bool loadAll();
    bool shutdown();

private:
    std::string _name;
    std::unordered_map<std::string, Table> _tables;
};

} // namespace dbms

#endif // DATABASE_H
