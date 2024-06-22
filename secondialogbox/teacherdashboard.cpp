#include "teacherdashboard.h"
#include "ui_teacherdashboard.h"

teacherdashboard::teacherdashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::teacherdashboard)
{
    ui->setupUi(this);
    this->resize(800,600);
    setWindowTitle("TeacherDashBoard");

    connect(ui->homeButton, &QPushButton::clicked, this, &teacherdashboard::showHomePage);
    connect(ui->assignmentButton, &QPushButton::clicked, this, &teacherdashboard::showAssignmentPage);
    connect(ui->internalButton, &QPushButton::clicked, this, &teacherdashboard::showInternalPage);
}

teacherdashboard::~teacherdashboard()
{
    delete ui;
}

void teacherdashboard::showHomePage() {
    ui->stackedWidget->setCurrentWidget(ui->Home);

}

void teacherdashboard::showAssignmentPage() {
    ui->stackedWidget->setCurrentWidget(ui->Assignment);
}

void teacherdashboard::showInternalPage() {
    ui->stackedWidget->setCurrentWidget(ui->Internal);
}




