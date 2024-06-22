#ifndef TEACHERWINDOW2_H
#define TEACHERWINDOW2_H

#include <QDialog>
#include"teacherwindow1.h"

namespace Ui {
class teacherwindow2;
}

class teacherwindow2 : public QDialog
{
    Q_OBJECT

public:
    explicit teacherwindow2(QWidget *parent = nullptr);
    ~teacherwindow2();

private:
    Ui::teacherwindow2 *ui;
};

#endif // TEACHERWINDOW2_H
