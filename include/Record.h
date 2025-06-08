#ifndef RECORD_H
#define RECORD_H

#include <vector>
#include <string>

namespace dbms {

using Field = std::string;  // 所有字段都以字符串形式存储

struct Record {
    int id;                    // 记录唯一标识或主键
    std::vector<Field> fields; // 每列的字段值列表
};

} // namespace dbms

#endif // RECORD_H
