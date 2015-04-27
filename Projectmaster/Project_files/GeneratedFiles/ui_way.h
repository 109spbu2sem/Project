/********************************************************************************
** Form generated from reading UI file 'way.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAY_H
#define UI_WAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_way
{
public:
    QLineEdit *lineEdit;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QDialog *way)
    {
        if (way->objectName().isEmpty())
            way->setObjectName(QStringLiteral("way"));
        way->resize(627, 136);
        lineEdit = new QLineEdit(way);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 601, 20));
        cancelButton = new QPushButton(way);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(530, 100, 75, 23));
        saveButton = new QPushButton(way);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(440, 100, 75, 23));

        retranslateUi(way);

        QMetaObject::connectSlotsByName(way);
    } // setupUi

    void retranslateUi(QDialog *way)
    {
        way->setWindowTitle(QApplication::translate("way", "Dialog", 0));
        lineEdit->setText(QApplication::translate("way", "C:\\", 0));
        cancelButton->setText(QApplication::translate("way", "Cancel", 0));
        saveButton->setText(QApplication::translate("way", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class way: public Ui_way {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAY_H
