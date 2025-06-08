#ifndef LOCK_MANAGER_H
#define LOCK_MANAGER_H

#include <string>
#include <map>

namespace dbms {

enum class LockMode { SHARED, EXCLUSIVE };

class LockManager {
public:
    /**
     * 申请锁
     * @param txId     事务 ID
     * @param resource 资源标识（如 "table:users"）
     * @param mode     锁模式（共享/排他）
     * @return 成功返回 true，否则 false（如死锁或冲突）
     */
    bool acquire(int txId, const std::string& resource, LockMode mode);

    /**
     * 释放锁
     * @param txId     事务 ID
     * @param resource 资源标识
     */
    void release(int txId, const std::string& resource);

private:
    std::map<std::string, int> _locks; // 资源到持有事务 ID 的映射
};

} // namespace dbms

#endif // LOCK_MANAGER_H