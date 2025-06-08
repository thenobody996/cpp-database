#ifndef DATABASE_H
#define DATABASE_H

#include "Table.h"
#include <unordered_map>
#include <string>

namespace dbms {

class Database {
public:
    /**
     * 构造函数
     * @param name 数据库名称
     */
    Database(const std::string& name);

    /**
     * 创建新表
     * @param name   表名
     * @param schema 表模式
     * @return 创建成功返回 true，否则 false（如表已存在）
     */
    bool createTable(const std::string& name, const Schema& schema);

    /**
     * 删除已存在的表
     * @param name 表名
     * @return 删除成功返回 true，否则 false（如表不存在）
     */
    bool dropTable(const std::string& name);

    /**
     * 获取表指针
     * @param name 表名
     * @return 指向 Table 的指针，找不到时返回 nullptr
     */
    Table* getTable(const std::string& name);

    /** 
     * 加载所有表的数据（启动时调用）
     * @return 全部加载成功返回 true，否则 false
     */
    bool loadAll();

    /** 
     * 关闭数据库并释放资源（退出时调用）
     * @return 成功返回 true，否则 false
     */
    bool shutdown();

private:
    std::string                                _name;   // 数据库名称
    std::unordered_map<std::string, Table>     _tables; // 名称到 Table 对象的映射
};

} // namespace dbms

#endif // DATABASE_H
