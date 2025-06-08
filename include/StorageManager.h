#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

#include <string>
#include <vector>

namespace dbms {

class StorageManager {
public:
    StorageManager(const std::string& dir);
    bool readPage(const std::string& filename, size_t pageId, std::vector<char>& buf);
    bool writePage(const std::string& filename, size_t pageId, const std::vector<char>& buf);
};

} // namespace dbms

#endif // STORAGE_MANAGER_H
