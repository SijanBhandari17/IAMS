#ifndef TEACHERDASHBOARD_H
#define TEACHERDASHBOARD_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class teacherdashboard;
}

class teacherdashboard : public QDialog
{
    Q_OBJECT

public:
    explicit teacherdashboard(QWidget *parent = nullptr);
    ~teacherdashboard();

private slots:

    void showHomePage();
    void showAssignmentPage();
    void showInternalPage();
    void logOut();

    void on_internalAdd_clicked();

    void on_internalUpdate_clicked();

    void on_internalDelete_clicked();

private:
    Ui::teacherdashboard *ui;
    QSqlDatabase mydb;
    bool connectionOpen();
    void connectionClose();
};

#endif // TEACHERDASHBOARD_H
