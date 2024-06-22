/********************************************************************************
** Form generated from reading UI file 'teacherdashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERDASHBOARD_H
#define UI_TEACHERDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_teacherdashboard
{
public:
    QWidget *icon_only_widget;
    QLabel *label;
    QPushButton *homeButton;
    QPushButton *assignmentButton;
    QPushButton *pushButton_6;
    QPushButton *internalButton;
    QStackedWidget *stackedWidget;
    QWidget *Home;
    QLabel *label_4;
    QWidget *Assignment;
    QLabel *label_3;
    QWidget *Internal;
    QLabel *label_5;
    QLabel *label_2;

    void setupUi(QDialog *teacherdashboard)
    {
        if (teacherdashboard->objectName().isEmpty())
            teacherdashboard->setObjectName("teacherdashboard");
        teacherdashboard->resize(712, 357);
        icon_only_widget = new QWidget(teacherdashboard);
        icon_only_widget->setObjectName("icon_only_widget");
        icon_only_widget->setGeometry(QRect(0, 0, 800, 600));
        label = new QLabel(icon_only_widget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 5, 40, 40));
        label->setMinimumSize(QSize(40, 40));
        label->setMaximumSize(QSize(40, 40));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/vecteezy_profile-icon-design-vector_5544718.jpg")));
        label->setScaledContents(true);
        homeButton = new QPushButton(icon_only_widget);
        homeButton->setObjectName("homeButton");
        homeButton->setGeometry(QRect(20, 80, 91, 41));
        homeButton->setMouseTracking(false);
        homeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        assignmentButton = new QPushButton(icon_only_widget);
        assignmentButton->setObjectName("assignmentButton");
        assignmentButton->setGeometry(QRect(10, 140, 111, 41));
        assignmentButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pushButton_6 = new QPushButton(icon_only_widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(30, 520, 50, 40));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        internalButton = new QPushButton(icon_only_widget);
        internalButton->setObjectName("internalButton");
        internalButton->setGeometry(QRect(10, 200, 121, 41));
        internalButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        stackedWidget = new QStackedWidget(icon_only_widget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(160, 40, 411, 391));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        Home = new QWidget();
        Home->setObjectName("Home");
        label_4 = new QLabel(Home);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(130, 100, 101, 61));
        QFont font;
        font.setPointSize(18);
        label_4->setFont(font);
        stackedWidget->addWidget(Home);
        Assignment = new QWidget();
        Assignment->setObjectName("Assignment");
        label_3 = new QLabel(Assignment);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 110, 141, 71));
        label_3->setFont(font);
        stackedWidget->addWidget(Assignment);
        Internal = new QWidget();
        Internal->setObjectName("Internal");
        label_5 = new QLabel(Internal);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(130, 120, 141, 61));
        label_5->setFont(font);
        stackedWidget->addWidget(Internal);
        label_2 = new QLabel(icon_only_widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 20, 40, 38));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/images/vecteezy_profile-icon-design-vector_5544718.jpg")));
        label_2->setScaledContents(true);

        retranslateUi(teacherdashboard);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(teacherdashboard);
    } // setupUi

    void retranslateUi(QDialog *teacherdashboard)
    {
        teacherdashboard->setWindowTitle(QCoreApplication::translate("teacherdashboard", "Dialog", nullptr));
        label->setText(QString());
        homeButton->setText(QCoreApplication::translate("teacherdashboard", "HOME", nullptr));
        assignmentButton->setText(QCoreApplication::translate("teacherdashboard", "ASSIGNMENT", nullptr));
        pushButton_6->setText(QCoreApplication::translate("teacherdashboard", "EXIT", nullptr));
        internalButton->setText(QCoreApplication::translate("teacherdashboard", "INTERNAL", nullptr));
        label_4->setText(QCoreApplication::translate("teacherdashboard", "Home", nullptr));
        label_3->setText(QCoreApplication::translate("teacherdashboard", "Assignment", nullptr));
        label_5->setText(QCoreApplication::translate("teacherdashboard", "INTERNAL", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class teacherdashboard: public Ui_teacherdashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERDASHBOARD_H
