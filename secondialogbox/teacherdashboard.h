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
    explicit teacherdashboard(QWidget *parent = nullptr, const QString &username = " ");
    ~teacherdashboard();

private slots:

    void showHomePage();

    void showAssignmentPage();

    void showInternalPage();

    void on_internalAdd_clicked();

    void on_internalUpdate_clicked();

    void on_internalDelete_clicked();

    void on_logOut_clicked();

private:
    Ui::teacherdashboard *ui;
    QSqlDatabase mydb;
    bool connectionOpen();
    void connectionClose();

    bool getAllDates(QString &dateString);

    QStringList checkExamDate(QStringList &dateList);

    QString t_username;

    bool matchcode(QString &username,QString &code);

};

#endif // TEACHERDASHBOARD_H
