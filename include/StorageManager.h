#ifndef STORAGE_MANAGER_H
#define STORAGE_MANAGER_H

#include <string>
#include <vector>

namespace dbms {

class StorageManager {
public:
    /**
     * 构造函数
     * @param dir 数据文件目录
     */
    StorageManager(const std::string& dir);

    /**
     * 读取指定文件的某页数据
     * @param filename 文件名
     * @param pageId   页号（从 0 开始）
     * @param buf      输出缓冲区，读取的数据写入其中
     * @return 成功返回 true，否则 false
     */
    bool readPage(const std::string& filename, size_t pageId, std::vector<char>& buf);

    /**
     * 向指定文件的某页写入数据
     * @param filename 文件名
     * @param pageId   页号
     * @param buf      待写入的数据缓冲区
     * @return 成功返回 true，否则 false
     */
    bool writePage(const std::string& filename, size_t pageId, const std::vector<char>& buf);

private:
    std::string _dir; // 数据文件所在目录
};

} // namespace dbms

#endif // STORAGE_MANAGER_H
