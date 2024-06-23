#include "studentdashboard.h"
#include "ui_studentdashboard.h"
#include"studentwindow1.h"
studentdashboard::studentdashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::studentdashboard)
{
    ui->setupUi(this);
    this->resize(800,600);
    setWindowTitle("StudentDashBoard");

    connect(ui->homeButton, &QPushButton::clicked, this, &studentdashboard::showHomePage);
    connect(ui->assignmentButton, &QPushButton::clicked, this, &studentdashboard::showAssignmentPage);
    connect(ui->internalButton, &QPushButton::clicked, this, &studentdashboard::showInternalPage);

}

studentdashboard::~studentdashboard()
{
    delete ui;
}

void studentdashboard::showHomePage() {
    ui->stackedWidget->setCurrentWidget(ui->Home);

}

void studentdashboard::showAssignmentPage() {
    ui->stackedWidget->setCurrentWidget(ui->Assignment);
}

void studentdashboard::showInternalPage() {
    ui->stackedWidget->setCurrentWidget(ui->Internal);
}


void studentdashboard::on_logOutButton_clicked()
{
    studentwindow1 *studentlogin = new studentwindow1;
    hide();
    studentlogin->show();

}

