#include "studentdashboard.h"
#include "ui_studentdashboard.h"
#include "studentwindow1.h"
#include <QMessageBox>
#include <QDebug>

studentdashboard::studentdashboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentdashboard)
{
    ui->setupUi(this);
    this->resize(800, 600);
    setWindowTitle("StudentDashBoard");

    connect(ui->homeButton, &QPushButton::clicked, this, &studentdashboard::on_homeButton_clicked);
    connect(ui->assignmentButton, &QPushButton::clicked, this, &studentdashboard::on_assignmentButton_clicked);
    connect(ui->internalButton, &QPushButton::clicked, this, &studentdashboard::on_internalButton_clicked);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/A S U S/Desktop/IAMS/database/iamsdata.db");

    if (!mydb.open()) {
        qDebug() << "Error: Failed to open database" << mydb.lastError().text();
        QMessageBox::critical(this, "Database Error", "Failed to open database");
    }
}

studentdashboard::~studentdashboard()
{
    delete ui;
}

void studentdashboard::on_logOutButton_clicked()
{
    studentwindow1 *studentlogin = new studentwindow1;
    hide();
    studentlogin->show();

    if (mydb.isOpen()) {
        mydb.close();
    }
}

void studentdashboard::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Home);
}

void studentdashboard::on_assignmentButton_clicked()
    {
        ui->stackedWidget->setCurrentWidget(ui->Assignment);
        QSqlQuery qry(mydb);
        if(qry.exec("SELECT * FROM Assignment")){
            QSqlQueryModel *modal = new QSqlQueryModel();
            modal -> setQuery(qry);
            ui->AssinmentTableView->setModel(modal);
            qDebug() << "Row count:" << modal ->rowCount();
        }else{
            qDebug() << "Query execution error:" << qry.lastError().text();
            QMessageBox::critical(this,"Query Error","Failed to execute query");
        }
    }


void studentdashboard::on_internalButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Internal);
    QSqlQuery qry(mydb);
    if (qry.exec("SELECT * FROM Exam")) {
        QSqlQueryModel *modal = new QSqlQueryModel();
        modal->setQuery(qry);
        ui->internalTableView->setModel(modal);
        qDebug() << "Row count:" << modal->rowCount();
    } else {
        qDebug() << "Query execution error:" << qry.lastError().text();
        QMessageBox::critical(this, "Query Error", "Failed to execute query");
    }
}

