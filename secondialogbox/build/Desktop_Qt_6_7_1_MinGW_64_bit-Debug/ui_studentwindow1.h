/********************************************************************************
** Form generated from reading UI file 'studentwindow1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTWINDOW1_H
#define UI_STUDENTWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_studentwindow1
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userEdit;
    QLabel *label_3;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okbutton;
    QPushButton *backbutton;

    void setupUi(QDialog *studentwindow1)
    {
        if (studentwindow1->objectName().isEmpty())
            studentwindow1->setObjectName("studentwindow1");
        studentwindow1->resize(649, 434);
        layoutWidget = new QWidget(studentwindow1);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 0, 611, 411));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:20px;\n"
"\n"
"}"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:15px\n"
"}"));

        verticalLayout->addWidget(label_2);

        userEdit = new QLineEdit(layoutWidget);
        userEdit->setObjectName("userEdit");
        userEdit->setMaximumSize(QSize(509, 16777215));
        userEdit->setFocusPolicy(Qt::StrongFocus);
        userEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:15px;\n"
"}"));
        userEdit->setEchoMode(QLineEdit::Normal);

        verticalLayout->addWidget(userEdit);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size: 15px;\n"
"}"));

        verticalLayout->addWidget(label_3);

        passwordEdit = new QLineEdit(layoutWidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"font-size:15px;\n"
"}"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okbutton = new QPushButton(layoutWidget);
        okbutton->setObjectName("okbutton");

        horizontalLayout->addWidget(okbutton);

        backbutton = new QPushButton(layoutWidget);
        backbutton->setObjectName("backbutton");

        horizontalLayout->addWidget(backbutton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(studentwindow1);

        QMetaObject::connectSlotsByName(studentwindow1);
    } // setupUi

    void retranslateUi(QDialog *studentwindow1)
    {
        studentwindow1->setWindowTitle(QCoreApplication::translate("studentwindow1", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("studentwindow1", "STUDENT LOGIN", nullptr));
        label_2->setText(QCoreApplication::translate("studentwindow1", "Username", nullptr));
        userEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("studentwindow1", "Password", nullptr));
        okbutton->setText(QCoreApplication::translate("studentwindow1", "Ok", nullptr));
        backbutton->setText(QCoreApplication::translate("studentwindow1", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentwindow1: public Ui_studentwindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW1_H
