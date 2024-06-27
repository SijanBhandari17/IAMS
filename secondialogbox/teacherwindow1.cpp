#include "teacherwindow1.h"
#include "ui_teacherwindow1.h"
#include"mainwindow.h"
#include<QLabel>
#include<QMessageBox>
#include<QSqlQuery>

SecDialog::SecDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecDialog)
{
    ui->setupUi(this);

     mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/A S U S/Desktop/IAMS/database/iamsdata.db");


    if(!mydb.open()) {

        ui->label_4->setText("Unable to open database");
        qWarning() << "Database error: " << mydb.lastError().text();
    } else {

        ui->label_4->setText("Connected...");
    }

    this->resize(800,600);
    setWindowTitle("TeacherLogin");

    connect(ui->ok,SIGNAL(clicked()),this,SLOT(okbutton()));
    connect(ui->backbutton,SIGNAL(clicked()),this,SLOT(backbutton()));


}

SecDialog::~SecDialog()
{
    delete ui;
}


void SecDialog::okbutton()
{
    QString username = ui->userEdit->text();
    QString password = ui->passwordEdit->text();

    if(!mydb.isOpen()){
        qDebug() << "Failed to open database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("SELECT * FROM Teacher WHERE username = :username AND password = :password");
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);

    if(qry.exec())
    {
        int count = 0;
        while(qry.next())
        {
            count++;
        }

        if(count == 1){
            ui->label_4->setText("Login successful");
            hide();
            TeacherDashBoard = new teacherdashboard(this);
            TeacherDashBoard->show();
        }
        else if(count > 1){
            ui->label_4->setText("Duplicate username or password");
        }
        else{
            ui->label_4->setText("Incorrect username or password");
        }
    }
    else
    {
        qDebug() << "Query execution error: " << qry.lastError().text();
    }
}



void SecDialog::backbutton()
{

    MainWindow *mainw = new MainWindow(this);
    hide();
    mainw->show();

}

