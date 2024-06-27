#ifndef TEACHERDASHBOARD_H
#define TEACHERDASHBOARD_H

#include <QDialog>

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

    void on_pushButton_6_clicked();

    void on_Update_clicked();

private:
    Ui::teacherdashboard *ui;
};

#endif // TEACHERDASHBOARD_H
