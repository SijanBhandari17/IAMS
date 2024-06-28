#include "database.h"

QSqlDatabase Database::db = QSqlDatabase::addDatabase("QSQLITE");
bool Database::isConnected = false;

QSqlDatabase& Database::getConnection() {
    if (!isConnected) {
        db.setDatabaseName("C:/Users/A S U S/Desktop/IAMS/database/iamsdata.db");
        if (!db.open()) {
            qDebug() << "Error: Unable to open database";
        } else {
            isConnected = true;
        }
    }
    return db;
}

void Database::closeConnection() {
    if (isConnected) {
        db.close();
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
        isConnected = false;
    }
}
