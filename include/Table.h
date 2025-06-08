#ifndef TABLE_H
#define TABLE_H

#include "Schema.h"
#include "Record.h"
#include <string>
#include <vector>

namespace dbms {

class Table {
public:
    Table(const std::string& name, const Schema& schema);
    const std::string& name() const;
    const Schema&      schema() const;

    void insert(const Record& rec);
    bool remove(int recordId);
    bool update(int recordId, const Record& rec);
    std::vector<Record> scan();

    // 持久化与加载
    bool loadFromDisk();
    bool flushToDisk();

private:
    std::string      _name;
    Schema           _schema;
    std::vector<Record> _data;  // 可配置为缓冲页模式
};

} // namespace dbms

#endif // TABLE_H
