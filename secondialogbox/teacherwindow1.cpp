#include "teacherwindow1.h"
#include "ui_teacherwindow1.h"
#include "mainwindow.h"
#include "teacherdashboard.h" // Include teacherdashboard header
#include <QLabel>
#include <QMessageBox>
#include <QSqlQuery>

SecDialog::SecDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecDialog)
{
    ui->setupUi(this);

    if(!connectionOpen()) {
        ui->label_4->setText("Unable to open database");
        qWarning() << "Database error: " << mydb.lastError().text();
    } else {
        ui->label_4->setText("Connected...");
    }

    this->resize(800, 600);
    setWindowTitle("TeacherLogin");

    connect(ui->ok, SIGNAL(clicked()), this, SLOT(okbutton()));
    connect(ui->backbutton, SIGNAL(clicked()), this, SLOT(backbutton()));
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::okbutton()
{
    QString username = ui->userEdit->text();
    QString password = ui->passwordEdit->text();

    if(!connectionOpen()){
        qDebug() << "Failed to open database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("SELECT * FROM Teacher WHERE userName = :username AND passWord = :password");
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
            connectionClose();
            hide();
            TeacherDashBoard = new teacherdashboard(this);
            TeacherDashBoard->show();
        }
        else if(count > 1){
            ui->label_4->setText("Duplicate username or password");
        }
        else{
            ui->label_4->setText("Incorrect username or password");
            ui->passwordEdit->setText("");
        }
    }
    else
    {
        qDebug() << "Query execution error: " << qry.lastError().text();
    }

    connectionClose();
}

void SecDialog::backbutton()
{
    MainWindow *mainw = new MainWindow(this);
    hide();
    mainw->show();
}
