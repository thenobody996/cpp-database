#ifndef BUFFER_MANAGER_H
#define BUFFER_MANAGER_H

#include <unordered_map>
#include <vector>

namespace dbms {

struct PageFrame {
    std::vector<char> data; // 页内容缓冲
    bool dirty;             // 是否被修改，需回写磁盘
    int  pinCount;          // 引用计数，防止被替换
};

class BufferManager {
public:
    /**
     * 构造缓冲池
     * @param poolSize 最大页框数量
     */
    BufferManager(size_t poolSize);

    /**
     * 获取指定页的内存指针
     * @param fname  文件名
     * @param pageId 页号
     * @return 内存中页面数据指针，失败返回 nullptr
     */
    char* getPage(const std::string& fname, size_t pageId);

    /**
     * 释放页框
     * @param fname  文件名
     * @param pageId 页号
     * @param dirty  是否有修改，若 true 则需要写回
     */
    void unpinPage(const std::string& fname, size_t pageId, bool dirty);

    /** 
     * 将所有脏页写回磁盘
     */
    void flushAll();

private:
    size_t _poolSize;                              // 缓冲池大小
    std::unordered_map<std::string, PageFrame> _frames; // 文件页到页框的映射
    // TODO: 添加 LRU 或其他替换策略的辅助成员
};

} // namespace dbms

#endif // BUFFER_MANAGER_H
