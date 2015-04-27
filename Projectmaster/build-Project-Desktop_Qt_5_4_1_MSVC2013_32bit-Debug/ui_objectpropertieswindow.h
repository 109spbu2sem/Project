/********************************************************************************
** Form generated from reading UI file 'objectpropertieswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECTPROPERTIESWINDOW_H
#define UI_OBJECTPROPERTIESWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_objectPropertiesWindow
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *objectTypeBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *textY1;
    QLineEdit *textX2;
    QLineEdit *textX1;
    QLineEdit *textY2;

    void setupUi(QDialog *objectPropertiesWindow)
    {
        if (objectPropertiesWindow->objectName().isEmpty())
            objectPropertiesWindow->setObjectName(QStringLiteral("objectPropertiesWindow"));
        objectPropertiesWindow->resize(208, 198);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(objectPropertiesWindow->sizePolicy().hasHeightForWidth());
        objectPropertiesWindow->setSizePolicy(sizePolicy);
        objectPropertiesWindow->setMinimumSize(QSize(208, 198));
        objectPropertiesWindow->setMaximumSize(QSize(208, 198));
        buttonBox = new QDialogButtonBox(objectPropertiesWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 160, 201, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        objectTypeBox = new QComboBox(objectPropertiesWindow);
        objectTypeBox->setObjectName(QStringLiteral("objectTypeBox"));
        objectTypeBox->setGeometry(QRect(50, 10, 101, 21));
        sizePolicy.setHeightForWidth(objectTypeBox->sizePolicy().hasHeightForWidth());
        objectTypeBox->setSizePolicy(sizePolicy);
        label = new QLabel(objectPropertiesWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 41, 16));
        label_2 = new QLabel(objectPropertiesWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 41, 16));
        label_4 = new QLabel(objectPropertiesWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 130, 41, 16));
        label_3 = new QLabel(objectPropertiesWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 100, 51, 16));
        textY1 = new QLineEdit(objectPropertiesWindow);
        textY1->setObjectName(QStringLiteral("textY1"));
        textY1->setGeometry(QRect(66, 72, 131, 22));
        textX2 = new QLineEdit(objectPropertiesWindow);
        textX2->setObjectName(QStringLiteral("textX2"));
        textX2->setEnabled(true);
        textX2->setGeometry(QRect(66, 101, 131, 22));
        textX2->setClearButtonEnabled(false);
        textX1 = new QLineEdit(objectPropertiesWindow);
        textX1->setObjectName(QStringLiteral("textX1"));
        textX1->setGeometry(QRect(66, 43, 131, 22));
        textY2 = new QLineEdit(objectPropertiesWindow);
        textY2->setObjectName(QStringLiteral("textY2"));
        textY2->setEnabled(true);
        textY2->setGeometry(QRect(66, 130, 131, 22));

        retranslateUi(objectPropertiesWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), objectPropertiesWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), objectPropertiesWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(objectPropertiesWindow);
    } // setupUi

    void retranslateUi(QDialog *objectPropertiesWindow)
    {
        objectPropertiesWindow->setWindowTitle(QApplication::translate("objectPropertiesWindow", "Dialog", 0));
        objectTypeBox->clear();
        objectTypeBox->insertItems(0, QStringList()
         << QApplication::translate("objectPropertiesWindow", "Point", 0)
         << QApplication::translate("objectPropertiesWindow", "Segment", 0)
         << QApplication::translate("objectPropertiesWindow", "Circle", 0)
        );
        label->setText(QApplication::translate("objectPropertiesWindow", "X:", 0));
        label_2->setText(QApplication::translate("objectPropertiesWindow", "Y:", 0));
        label_4->setText(QApplication::translate("objectPropertiesWindow", "Y2:", 0));
        label_3->setText(QApplication::translate("objectPropertiesWindow", "X2:", 0));
        textY1->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "Y", 0));
        textX2->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "X", 0));
        textX1->setText(QString());
        textX1->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "X", 0));
        textY2->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "Y", 0));
    } // retranslateUi

};

namespace Ui {
    class objectPropertiesWindow: public Ui_objectPropertiesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTPROPERTIESWINDOW_H
