#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

namespace dbms {
namespace utils {

std::vector<std::string> split(const std::string& s, char delim);
std::string          trim(const std::string& s);
std::string          serializeInt(int x);
int                  deserializeInt(const std::string& s);

} // namespace utils
} // namespace dbms

#endif // UTILS_H
