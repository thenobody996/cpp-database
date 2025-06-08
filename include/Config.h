#ifndef CONFIG_H
#define CONFIG_H

#include <string>

namespace dbms {

class Config {
public:
    /** 
     * 初始化配置：
     * @param path 指定的配置文件或数据目录路径（可选），为空时使用默认
     * @return 成功返回 true，失败返回 false
     */
    static bool init(const std::string& path = "");

    // 数据文件存放目录
    static const std::string DATA_DIR;
    // 页大小（字节），用于磁盘 I/O 分块
    static const size_t PAGE_SIZE;
};

} // namespace dbms

#endif // CONFIG_H
