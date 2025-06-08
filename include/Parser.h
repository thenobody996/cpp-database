#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <memory>
#include "Query.h"

namespace dbms {

class Parser {
public:
    /**
     * 解析 SQL 语句字符串为 Query 对象
     * @param sql 待解析的 SQL 文本，例如 "INSERT INTO ..."
     * @return 指向 Query 派生对象的智能指针，解析失败时可返回 nullptr
     */
    std::unique_ptr<Query> parse(const std::string& sql);
};

} // namespace dbms

#endif // PARSER_H
