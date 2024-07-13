#include "studentwindow1.h"
#include "ui_studentwindow1.h"
#include <QMessageBox>
#include <QDebug>
#include "mainwindow.h"

studentwindow1::studentwindow1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::studentwindow1)
{
    ui->setupUi(this);

    if(!connectionOpen()) {
        ui->status->setText("Unable to open database");
        qWarning() << "Database error: " << mydb.lastError().text();
    } else {
        ui->status->setText("Connected...");
    }

    this->resize(800, 600);
    setWindowTitle("StudentLogin");

    connect(ui->ok, &QPushButton::clicked, this, &studentwindow1::okbutton);
    connect(ui->backbutton, &QPushButton::clicked, this, &studentwindow1::backbutton);
    ui->stackedWidget->setCurrentWidget(ui->mainPage);
    ui->userEdit2->setPlaceholderText("Enter Username");
    ui->passwordEdit3->setPlaceholderText("Enter new Password");
    ui->passwordEdit2->setPlaceholderText("Confirm Password");
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

    if (!connectionOpen()) {
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
            ui->status->setText("Login successful");
            hide();
            StudentDashBoard = new studentdashboard(this);
            StudentDashBoard->show();
        } else if (count > 1) {
            ui->status->setText("Duplicate username or password");
        } else {
            ui->status->setText("Incorrect username or password");
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

void studentwindow1::on_changepasswordButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->passwordPage);

}

bool studentwindow1::containsNumber(QString &str)
{
    for (QChar c : str) {
        if (c.isDigit()) {


            return true;
        }

    }

    return false;
}

void studentwindow1::on_backButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->mainPage);
}

void studentwindow1::on_changeButton_clicked()
{
    QString username = ui->userEdit2->text();
    QString password = ui->passwordEdit2->text();
    QString cpassword = ui->passwordEdit3->text();

    if(username.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Username cannot be empty");
        return;
    }

    if(password != cpassword)
    {
        QMessageBox::critical(this, "Error", "Entered password and confirmation password do not match");
        return;
    }

    if(containsNumber(password))
    {
        if (!connectionOpen()) {
            qDebug() << "Failed to open database";
            return;
        }

        QSqlQuery qry;
        qry.prepare("UPDATE Student SET passWord = :password WHERE userName = :username");
        qry.bindValue(":password", password);
        qry.bindValue(":username", username);

        if (!qry.exec()) {
            QMessageBox::information(this, "Error", "Failed to change password");
            qDebug() << "Query error: " << qry.lastError().text();
        } else {
            QMessageBox::information(this, "Saved", "Password changed successfully");
        }
    }
    else {
        QMessageBox::information(this, "Error", "Password should contain a number");
    }
}

