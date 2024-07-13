#ifndef STUDENTWINDOW1_H
#define STUDENTWINDOW1_H

#include <QDialog>
#include <QtSql>
#include "studentdashboard.h"

namespace Ui {
class studentwindow1;
}

class studentwindow1 : public QDialog
{
    Q_OBJECT

public:
    bool connectionOpen()
    {
        if (QSqlDatabase::contains("qt_sql_default_connection")) {
            mydb = QSqlDatabase::database("qt_sql_default_connection");
        } else {
            mydb = QSqlDatabase::addDatabase("QSQLITE");
            mydb.setDatabaseName("C:/Users/A S U S/Desktop/IAMS/database/iamsdata.db");
        }

        if(!mydb.open()) {
            qDebug() << "Database error: " << mydb.lastError().text();
            return false;
        } else {
            return true;
        }
    }

    void connectionClose()
    {
        if(mydb.isOpen()) {
            mydb.close();
        }
    }

public:
    explicit studentwindow1(QWidget *parent = nullptr);
    ~studentwindow1();

private slots:
    void okbutton();

    void backbutton();

    void on_backButton_clicked();

    bool containsNumber(QString &str);





    void on_changepasswordButton_clicked();

    void on_changeButton_clicked();

private:
    Ui::studentwindow1 *ui;
    QSqlDatabase mydb;
    studentdashboard *StudentDashBoard;
};

#endif // STUDENTWINDOW1_H
