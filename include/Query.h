#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <vector>
#include "Record.h"

namespace dbms {

class Query {
public:
    virtual ~Query() = default;
    virtual void execute(class Database& db) = 0;
};

class InsertQuery : public Query {
public:
    InsertQuery(const std::string& tbl, const Record& rec);
    void execute(Database& db) override;
private:
    std::string _table;
    Record      _rec;
};

class SelectQuery : public Query {
public:
    SelectQuery(const std::string& tbl);
    void execute(Database& db) override;
    const std::vector<Record>& result() const;
private:
    std::string            _table;
    std::vector<Record>    _res;
};

// 可按需添加 UpdateQuery、DeleteQuery、CreateTableQuery 等

} // namespace dbms

#endif // QUERY_H
