#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

namespace dbms {

enum class LogLevel { DEBUG, INFO, WARN, ERROR };

class Logger {
public:
    static void init(const std::string& logfile);
    static void log(LogLevel level, const std::string& msg);
};

} // namespace dbms

#endif // LOGGER_H
