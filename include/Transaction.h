#ifndef TRANSACTION_H
#define TRANSACTION_H

namespace dbms {

class Transaction {
public:
    /**
     * 构造事务
     * @param id 事务唯一标识
     */
    Transaction(int id);

    /** 开始事务 */
    void begin();

    /** 提交事务 */
    void commit();

    /** 回滚事务 */
    void rollback();

private:
    int _id; // 事务 ID
};

} // namespace dbms

#endif // TRANSACTION_H