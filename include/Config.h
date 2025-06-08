#ifndef CONFIG_H
#define CONFIG_H

#include <string>

namespace dbms {

class Config {
public:
    static const std::string DATA_DIR;      // 数据文件存放目录
    static const size_t    PAGE_SIZE;       // 页大小，单位字节
    static bool init(const std::string& path = "");
};

} // namespace dbms

#endif // CONFIG_H
