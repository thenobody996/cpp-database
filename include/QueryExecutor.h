#ifndef QUERY_EXECUTOR_H
#define QUERY_EXECUTOR_H

#include "Database.h"
#include "Query.h"
#include <memory>
#include <vector>

namespace dbms {

class QueryExecutor {
public:
    QueryExecutor(Database& db);
    void execute(std::unique_ptr<Query> q);
    // 可扩展事务、日志等功能
private:
    Database& _db;
};

} // namespace dbms

#endif // QUERY_EXECUTOR_H
