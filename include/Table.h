#ifndef TABLE_H
#define TABLE_H

#include "Schema.h"
#include "Record.h"
#include <string>
#include <vector>

namespace dbms {

class Table {
public:
    /**
     * 构造函数
     * @param name  表名
     * @param schema 表模式
     */
    Table(const std::string& name, const Schema& schema);

    /** 
     * 获取表名
     * @return 表名字符串
     */
    const std::string& name() const;

    /**
     * 获取表模式
     * @return Schema 对象引用
     */
    const Schema& schema() const;

    /**
     * 插入新记录
     * @param rec 待插入的 Record 对象
     */
    void insert(const Record& rec);

    /**
     * 根据记录 ID 删除记录
     * @param recordId 要删除的记录的 id
     * @return 删除成功返回 true，否则 false
     */
    bool remove(int recordId);

    /**
     * 更新已存在的记录
     * @param recordId 要更新的记录 id
     * @param rec      新的 Record 数据
     * @return 更新成功返回 true，否则 false
     */
    bool update(int recordId, const Record& rec);

    /**
     * 扫描并返回所有记录
     * @return 记录列表向量
     */
    std::vector<Record> scan();

    /** 
     * 从磁盘加载表数据
     * @return 成功返回 true，否则 false
     */
    bool loadFromDisk();

    /** 
     * 将当前内存数据写回磁盘
     * @return 成功返回 true，否则 false
     */
    bool flushToDisk();

private:
    std::string         _name;   // 表名
    Schema              _schema; // 表对应模式
    std::vector<Record> _data;   // 内存中的记录列表
};

} // namespace dbms

#endif // TABLE_H
