#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

namespace dbms {
namespace utils {

/**
 * 将字符串按指定分隔符拆分为子串列表
 * @param s 待拆分字符串
 * @param delim 分隔符字符
 * @return 子串向量
 */
std::vector<std::string> split(const std::string& s, char delim);

/**
 * 去除字符串首尾空白（空格、制表符等）
 * @param s 待处理字符串
 * @return 去除前后空白后的字符串
 */
std::string trim(const std::string& s);

/**
 * 将整数序列化为字符串（可用于存储）
 * @param x 待序列化整数
 * @return 对应的字符串
 */
std::string serializeInt(int x);

/**
 * 从字符串反序列化出整数
 * @param s 序列化格式的字符串
 * @return 解析得到的整数
 */
int deserializeInt(const std::string& s);

} // namespace utils
} // namespace dbms

#endif // UTILS_H
