#include "teacherwindow2.h"
#include "ui_teacherwindow2.h"

teacherwindow2::teacherwindow2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::teacherwindow2)
{
    ui->setupUi(this);
    this->resize(800,600);
}

teacherwindow2::~teacherwindow2()
{
    delete ui;
}
