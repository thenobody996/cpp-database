#ifndef RECORD_H
#define RECORD_H

#include <vector>
#include <string>

namespace dbms {

using Field = std::string;  // 简化：所有类型都以字符串存储

struct Record {
    int                    id;     // 主键或内部标识
    std::vector<Field>     fields; // 各列数据
};

} // namespace dbms

#endif // RECORD_H
