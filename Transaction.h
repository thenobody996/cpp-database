#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
namespace dbms {

class Transaction {
public:
    Transaction(int id);
    void begin();
    void commit();
    void rollback();
private:
    int _id;
};

} // namespace dbms
#endif // TRANSACTION_H