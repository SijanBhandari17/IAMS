/********************************************************************************
** Form generated from reading UI file 'studentdashboard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTDASHBOARD_H
#define UI_STUDENTDASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_studentdashboard
{
public:

    void setupUi(QDialog *studentdashboard)
    {
        if (studentdashboard->objectName().isEmpty())
            studentdashboard->setObjectName("studentdashboard");
        studentdashboard->resize(400, 300);

        retranslateUi(studentdashboard);

        QMetaObject::connectSlotsByName(studentdashboard);
    } // setupUi

    void retranslateUi(QDialog *studentdashboard)
    {
        studentdashboard->setWindowTitle(QCoreApplication::translate("studentdashboard", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentdashboard: public Ui_studentdashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTDASHBOARD_H
