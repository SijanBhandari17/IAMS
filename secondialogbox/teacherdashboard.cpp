#include "teacherdashboard.h"
#include "ui_teacherdashboard.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include "teacherwindow1.h"

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

void teacherdashboard::on_internalUpdate_clicked()
{
    QString block = ui->blockEdit->text();
    QString room = ui->roomEdit->text();
    QString code = ui->courseEdit->text();
    QTime selectedTime = ui->timeEdit->time();
    QString timeString = selectedTime.toString("HH:mm:ss");
    QDate selectedDate = ui->dateEdit->date();
    QString dateString = selectedDate.toString("MM/dd/yyyy");

    if (code.isEmpty()) {
        QMessageBox::information(this, "Error", "Course Code is required to update the record.");
        return;
    }

    if (!connectionOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("UPDATE Exam SET Block = :block, RoomNo = :room, Time = :time, Date = :date WHERE Course_Code = :code");
    qry.bindValue(":block", block);
    qry.bindValue(":room", room);
    qry.bindValue(":time", timeString);
    qry.bindValue(":date", dateString);
    qry.bindValue(":code", code);

    if (qry.exec()) {
        QMessageBox::information(this, "Updated", "Data has been updated successfully.");
    } else {
        QMessageBox::information(this, "Error", "Failed to update data.");
        qDebug() << "Query execution error: " << qry.lastError().text();
    }

    connectionClose();
}

void teacherdashboard::on_internalAdd_clicked()
{
    QString block = ui->blockEdit->text();
    QString room = ui->roomEdit->text();
    QString code = ui->courseEdit->text();
    QTime selectedTime = ui->timeEdit->time();
    QString timeString = selectedTime.toString("HH:mm:ss");
    QDate selectedDate = ui->dateEdit->date();
    QString dateString = selectedDate.toString("MM/dd/yyyy");

    if (!connectionOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    if (code.isEmpty()) {
        QMessageBox::information(this, "Error", "Course Code is required to add the record.");
        connectionClose();
        return;
    }

      if (getAllDates(dateString)) {
        connectionOpen();
        QSqlQuery qry;
        qry.prepare("INSERT INTO Exam (Course_Code, Block, RoomNo, Time, Date) VALUES (:code, :block, :room, :time, :date)");
        qry.bindValue(":code", code);
        qry.bindValue(":block", block);
        qry.bindValue(":room", room);
        qry.bindValue(":time", timeString);
        qry.bindValue(":date", dateString);

        if (!qry.exec()) {
            QMessageBox::information(this, "Error", "Failed to save data.");
            qDebug() << "Query error: " << qry.lastError().text();

        } else {
          QMessageBox::information(this, "Saved", "Data has been saved successfully.");
        }
    } else {
         QMessageBox::critical(this, "Cannot", "The date is already taken");
     }

    connectionClose();
}


void teacherdashboard::on_internalDelete_clicked()
{
    QString code = ui->courseEdit->text();

    if (code.isEmpty()) {
        QMessageBox::information(this, "Error", "Please enter a Course Code to delete.");
        return;
    }

    if (!connectionOpen()) {
        qDebug() << "Failed to open database";
        return;
    }

    QSqlQuery qry;
    qry.prepare("DELETE FROM Exam WHERE Course_Code = :code");
    qry.bindValue(":code", code);

    if (qry.exec()) {
        QMessageBox::information(this, "Deleted", "Data has been deleted successfully.");
    } else {
        QMessageBox::information(this, "Error", "Failed to delete data.");
        qDebug() << "Query execution error: " << qry.lastError().text();
    }

    connectionClose();
}

bool teacherdashboard::getAllDates(QString &dateString)
{
    QStringList dateList;

    if (!connectionOpen()) {
        qDebug() << "Failed to open database";
        return false;
    }

    QSqlQuery qry;
    qry.prepare("SELECT Date FROM Exam");
    if (qry.exec()) {
        while (qry.next()) {
            QString date = qry.value(0).toString();
            dateList.append(date);
        }
    } else {
        qDebug() << "Query execution error: " << qry.lastError().text();
        connectionClose();
        return false;
    }

    connectionClose();

    QStringList updatedDateList = checkExamDate(dateList);

    if (updatedDateList.contains(dateString)) {
        return false;
    }

    return true;
}

QStringList teacherdashboard::checkExamDate(QStringList &dateList) {
    QStringList tempList;

    for (int i = 0; i < dateList.size(); ++i) {
        QString dateString = dateList[i];

        QDate originalDate = QDate::fromString(dateString, "MM/dd/yyyy");

        if (!originalDate.isValid()) {
            qDebug() << "Invalid date format:" << dateString;
            continue;
        }

        QDate increasedDate = originalDate.addDays(1);
        QString increasedDateString = increasedDate.toString("MM/dd/yyyy");

        dateList[i] = increasedDateString;

        QDate decreasedDate = originalDate.addDays(-1);
        QString decreasedDateString = decreasedDate.toString("MM/dd/yyyy");

        tempList.append(decreasedDateString);
    }

    dateList.append(tempList);

    return dateList;
}

void teacherdashboard::on_logOut_clicked()
{
    SecDialog *teacherlogin = new SecDialog;
    hide();
    teacherlogin->show();
}
