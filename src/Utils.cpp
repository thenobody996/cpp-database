#include "Utils.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <stdexcept>

namespace dbms {
namespace utils {

std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

std::string trim(const std::string& s) {
    size_t start = 0;
    while (start < s.length() && std::isspace(static_cast<unsigned char>(s[start]))) {
        ++start;
    }

    if (start == s.length()) return ""; // 全是空格

    size_t end = s.length() - 1;
    while (end > start && std::isspace(static_cast<unsigned char>(s[end]))) {
        --end;
    }

    return s.substr(start, end - start + 1);
}

std::string serializeInt(int x) {
    return std::to_string(x);
}

int deserializeInt(const std::string& s) {
    try {
        return std::stoi(s);
    } catch (const std::invalid_argument& e) {
        return 0; // 或抛出错误
    } catch (const std::out_of_range& e) {
        return 0; // 或抛出错误
    }
}

} // namespace utils
} // namespace dbms
