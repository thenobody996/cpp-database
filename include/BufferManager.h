#ifndef BUFFER_MANAGER_H
#define BUFFER_MANAGER_H

#include <unordered_map>
#include <vector>

namespace dbms {

struct PageFrame {
    std::vector<char> data;
    bool dirty;
    int  pinCount;
};

class BufferManager {
public:
    BufferManager(size_t poolSize);
    char*  getPage(const std::string& fname, size_t pageId);
    void   unpinPage(const std::string& fname, size_t pageId, bool dirty);
    void   flushAll();
private:
    size_t _poolSize;
    std::unordered_map<std::string, PageFrame> _frames;
    // 可添加替换策略（LRU 等）成员
};

} // namespace dbms

#endif // BUFFER_MANAGER_H
