#ifndef TEACHERWINDOW1_H
#define TEACHERWINDOW1_H
#include"teacherdashboard.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QDialog>
namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

private slots:
    void okbutton();

    void backbutton();

private:
    Ui::SecDialog *ui;
    QSqlDatabase mydb;
    teacherdashboard *TeacherDashBoard;
};

#endif // TEACHERWINDOW1_H
