#ifndef QUERY_EXECUTOR_H
#define QUERY_EXECUTOR_H

#include "Database.h"
#include "Query.h"
#include <memory>

namespace dbms {

class QueryExecutor {
public:
    /**
     * 构造函数
     * @param db 引用的数据库实例
     */
    QueryExecutor(Database& db);

    /**
     * 执行传入的 Query
     * @param q 唯一指针，指向要执行的查询对象
     */
    void execute(std::unique_ptr<Query> q);

private:
    Database& _db; // 引用的数据库实例
};

} // namespace dbms

#endif // QUERY_EXECUTOR_H
