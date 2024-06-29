#ifndef STUDENTDASHBOARD_H
#define STUDENTDASHBOARD_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class studentdashboard;
}

class studentdashboard : public QDialog
{
    Q_OBJECT

public:
    explicit studentdashboard(QWidget *parent = nullptr);
    ~studentdashboard();
private slots:

    void on_logOutButton_clicked();

    void on_homeButton_clicked();

    void on_assignmentButton_clicked();

    void on_internalButton_clicked();

private:
    Ui::studentdashboard *ui;
    QSqlDatabase mydb;
};

#endif // STUDENTDASHBOARD_H
