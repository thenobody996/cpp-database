#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <vector>
#include "Record.h"

namespace dbms {

class Database; // 前向声明

class Query {
public:
    virtual ~Query() = default;
    /**
     * 执行该查询
     * @param db 数据库实例引用
     */
    virtual void execute(Database& db) = 0;
};

class InsertQuery : public Query {
public:
    /**
     * 构造插入查询
     * @param tbl 目标表名
     * @param rec 要插入的记录
     */
    InsertQuery(const std::string& tbl, const Record& rec);

    /**
     * 执行插入操作
     * @param db 数据库实例
     */
    void execute(Database& db) override;

private:
    std::string _table; // 目标表名
    Record      _rec;   // 插入的记录数据
};

class SelectQuery : public Query {
public:
    /**
     * 构造查询
     * @param tbl 要查询的表名
     */
    SelectQuery(const std::string& tbl);

    /**
     * 执行查询并填充结果
     * @param db 数据库实例
     */
    void execute(Database& db) override;

    /**
     * 获取查询结果
     * @return 查询到的记录列表
     */
    const std::vector<Record>& result() const;

private:
    std::string            _table; // 查询表名
    std::vector<Record>    _res;   // 存储查询结果
};

// TODO: 可按需添加 UpdateQuery、DeleteQuery、CreateTableQuery 等

} // namespace dbms

#endif // QUERY_H
