#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class Database {
public:
    static QSqlDatabase& getConnection();
    static void closeConnection();

private:
    static QSqlDatabase db;
    static bool isConnected;
};

#endif // DATABASE_H
