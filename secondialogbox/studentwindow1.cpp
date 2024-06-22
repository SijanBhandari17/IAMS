#include "studentwindow1.h"
#include "ui_studentwindow1.h"
#include<QMessageBox>
#include<QDialog>
#include"mainwindow.h"

studentwindow1::studentwindow1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::studentwindow1)
{
    ui->setupUi(this);
    this->resize(800,600);
    setWindowTitle("StudentLogin");

    connect(ui->okbutton,SIGNAL(clicked()),this,SLOT(okbutton()));
    connect(ui->backbutton,SIGNAL(clicked()),this,SLOT(backbutton()));

}






studentwindow1::~studentwindow1()
{
    delete ui;
}

void studentwindow1::okbutton()
{



        QString username = ui->userEdit->text();
        QString password = ui->passwordEdit->text();

        QString name[]={"SIJAN","PRABESH","KESHAV","SUJAN"};
        QString code[]={"123","456","789","101112"};

        bool found = false;
        int i;
        for(i = 0; i< name->length();i++)
        {
            if(username == name[i] && password == code[i])
            {
                found = true;
                hide();
                QMessageBox::information(this,"Success","Welcome to department of computer science and engineering");

            }
        }

        if (!found)
        {
            QMessageBox::warning(this,"Error Box","Wrong username and password");
        }



}




void studentwindow1::backbutton()
{

    MainWindow *mainw = new MainWindow(this);
    hide();
    mainw->show();

}

