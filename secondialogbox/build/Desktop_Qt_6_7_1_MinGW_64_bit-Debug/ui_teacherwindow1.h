/********************************************************************************
** Form generated from reading UI file 'teacherwindow1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERWINDOW1_H
#define UI_TEACHERWINDOW1_H

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

class Ui_SecDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userEdit;
    QLabel *label_3;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok;
    QPushButton *backbutton;

    void setupUi(QDialog *SecDialog)
    {
        if (SecDialog->objectName().isEmpty())
            SecDialog->setObjectName("SecDialog");
        SecDialog->resize(800, 600);
        layoutWidget = new QWidget(SecDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 10, 611, 411));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

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

        ok = new QPushButton(layoutWidget);
        ok->setObjectName("ok");

        horizontalLayout->addWidget(ok);

        backbutton = new QPushButton(layoutWidget);
        backbutton->setObjectName("backbutton");

        horizontalLayout->addWidget(backbutton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SecDialog);

        QMetaObject::connectSlotsByName(SecDialog);
    } // setupUi

    void retranslateUi(QDialog *SecDialog)
    {
        SecDialog->setWindowTitle(QCoreApplication::translate("SecDialog", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("SecDialog", "[+]status", nullptr));
        label->setText(QCoreApplication::translate("SecDialog", " TEACHER LOGIN", nullptr));
        label_2->setText(QCoreApplication::translate("SecDialog", "Username", nullptr));
        userEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("SecDialog", "Password", nullptr));
        ok->setText(QCoreApplication::translate("SecDialog", "Ok", nullptr));
        backbutton->setText(QCoreApplication::translate("SecDialog", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecDialog: public Ui_SecDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERWINDOW1_H
