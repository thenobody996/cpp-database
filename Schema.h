#ifndef SCHEMA_H
#define SCHEMA_H

#include <string>
#include <vector>

namespace dbms {

enum class FieldType { INT, FLOAT, STRING };

struct Column {
    std::string name;
    FieldType   type;
};

class Schema {
public:
    Schema() = default;
    void addColumn(const std::string& name, FieldType type);
    const std::vector<Column>& columns() const;
private:
    std::vector<Column> _cols;
};

} // namespace dbms

#endif // SCHEMA_H
