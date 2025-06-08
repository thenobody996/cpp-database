// LockManager.h
#ifndef LOCK_MANAGER_H
#define LOCK_MANAGER_H

#include <string>
#include <map>
namespace dbms {

enum class LockMode { SHARED, EXCLUSIVE };

class LockManager {
public:
    bool acquire(int txId, const std::string& resource, LockMode mode);
    void release(int txId, const std::string& resource);
private:
    std::map<std::string, int> _locks;
};

} // namespace dbms

#endif // LOCK_MANAGER_H