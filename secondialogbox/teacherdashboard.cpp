#include "teacherdashboard.h"
#include "ui_teacherdashboard.h"
#include "teacherwindow1.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

teacherdashboard::teacherdashboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::teacherdashboard)
{
    ui->setupUi(this);
    this->resize(800, 600);
    setWindowTitle("TeacherDashBoard");

    connect(ui->homeButton, &QPushButton::clicked, this, &teacherdashboard::showHomePage);
    connect(ui->assignmentButton, &QPushButton::clicked, this, &teacherdashboard::showAssignmentPage);
    connect(ui->internalButton, &QPushButton::clicked, this, &teacherdashboard::showInternalPage);

    if (!connectionOpen()) {
        ui->status->setText("Unable to open database");
    } else {
        ui->status->setText("Connected...");
    }
}

teacherdashboard::~teacherdashboard()
{
    connectionClose();
    delete ui;
}

bool teacherdashboard::connectionOpen()
{
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        mydb = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/A S U S/Desktop/IAMS/database/iamsdata.db");
    }

    if (!mydb.open()) {
        qDebug() << "Database error: " << mydb.lastError().text();
        return false;
    } else {
        return true;
    }
}

void teacherdashboard::connectionClose()
{
    if (mydb.isOpen()) {
        mydb.close();
    }
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

void teacherdashboard::logOut()
{
    SecDialog *teacherlogin = new SecDialog;
    hide();
    teacherlogin->show();
}

void teacherdashboard::on_internalupdate_clicked()
{
    QString block = ui->blockEdit->text();
    QString room = ui->roomEdit->text();
    QString code = ui->courseEdit->text();

    if (!connectionOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("INSERT INTO Exam (Course_Code, Block, RoomNo) VALUES (:code, :block, :room)");
    qry.bindValue(":code", code);
    qry.bindValue(":block", block);
    qry.bindValue(":room", room);

    if (qry.exec()) {
        QMessageBox::information(this, "Saved", "Data has been saved successfully.");
    } else {
        QMessageBox::information(this, "Error", "Failed to save data.");
        qDebug() << "Query execution error: " << qry.lastError().text();
    }

    connectionClose();
}

