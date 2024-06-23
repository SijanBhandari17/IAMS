#include "studentwindow1.h"
#include "ui_studentwindow1.h"
#include <QMessageBox>
#include <QDebug>
#include"mainwindow.h"
studentwindow1::studentwindow1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::studentwindow1)
{
    ui->setupUi(this);
    this->resize(800, 600);
    setWindowTitle("TeacherLogin");

    connect(ui->ok, SIGNAL(clicked()), this, SLOT(okbutton()));
    connect(ui->backbutton, SIGNAL(clicked()), this, SLOT(backbutton()));

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/Suresh/Desktop/prabesh/IAMS/database/iamsdata.db");

    if(!mydb.open()) {
        ui->label_4->setText("Unable to open database");
        qWarning() << "Database error: " << mydb.lastError().text();
    } else {
        ui->label_4->setText("Connected...");
    }
}

studentwindow1::~studentwindow1()
{
    delete ui;
    if (mydb.isOpen()) {
        mydb.close();
    }
}

void studentwindow1::okbutton()
{
    QString username = ui->userEdit->text();
    QString password = ui->passwordEdit->text();

    if (!mydb.isOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("SELECT * FROM Student WHERE userName = :username AND password = :password");
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);

    if (qry.exec()) {
        int count = 0;
        while (qry.next()) {
            count++;
        }

        qDebug() << "Count: " << count;

        if (count == 1) {
            ui->label_4->setText("Login successful");
            hide();
            StudentDashBoard = new studentdashboard(this);
            StudentDashBoard->show();
        } else if (count > 1) {
            ui->label_4->setText("Duplicate username or password");
        } else {
            ui->label_4->setText("Incorrect username or password");
        }
    } else {
        qDebug() << "Query execution error: " << qry.lastError().text();
    }
}

void studentwindow1::backbutton()
{
    MainWindow *mainw = new MainWindow(this);
    hide();
    mainw->show();


}
