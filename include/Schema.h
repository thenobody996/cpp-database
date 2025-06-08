#ifndef SCHEMA_H
#define SCHEMA_H

#include <string>
#include <vector>

namespace dbms {

enum class FieldType { INT, FLOAT, STRING };

struct Column {
    std::string name;   // 列名
    FieldType   type;   // 列的数据类型
};

class Schema {
public:
    /** 
     * 添加一列到模式中：
     * @param name 列名
     * @param type 列类型（INT/FLOAT/STRING）
     */
    void addColumn(const std::string& name, FieldType type);

    /**
     * 获取当前所有列定义
     * @return 列向量（Column 列表）
     */
    const std::vector<Column>& columns() const;

private:
    std::vector<Column> _cols; // 内部存储的列定义列表
};

} // namespace dbms

#endif // SCHEMA_H
