#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <memory>
#include "Query.h"

namespace dbms {

class Parser {
public:
    // 解析 SQL 语句，返回对应的 Query 对象
    std::unique_ptr<Query> parse(const std::string& sql);
};

} // namespace dbms

#endif // PARSER_H
