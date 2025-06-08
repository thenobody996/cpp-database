#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

namespace dbms {

enum class LogLevel { DEBUG, INFO, WARN, ERROR };

class Logger {
public:
    /** 
     * 初始化日志系统：
     * @param logfile 日志输出文件路径
     */
    static void init(const std::string& logfile);

    /** 
     * 输出日志：
     * @param level 日志级别（DEBUG/INFO/WARN/ERROR）
     * @param msg   日志消息内容
     */
    static void log(LogLevel level, const std::string& msg);
};

} // namespace dbms

#endif // LOGGER_H
