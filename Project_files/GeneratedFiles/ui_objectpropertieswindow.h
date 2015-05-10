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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_objectPropertiesWindow
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelR_2;
    QLineEdit *editR;
    QLabel *labelG_2;
    QLineEdit *editG;
    QLabel *labelB_2;
    QLineEdit *editB;
    QComboBox *typesOfObjects;
    QLineEdit *editID;
    QLabel *label_5;
    QWidget *layoutWidget_2;
    QFormLayout *formLayout;
    QLabel *labelX1;
    QLineEdit *editX1;
    QLabel *labelY1;
    QLineEdit *editY1;
    QLabel *labelX2;
    QLineEdit *editX2;
    QLabel *labelY2;
    QLineEdit *editY2;

    void setupUi(QDialog *objectPropertiesWindow)
    {
        if (objectPropertiesWindow->objectName().isEmpty())
            objectPropertiesWindow->setObjectName(QStringLiteral("objectPropertiesWindow"));
        objectPropertiesWindow->resize(183, 227);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(objectPropertiesWindow->sizePolicy().hasHeightForWidth());
        objectPropertiesWindow->setSizePolicy(sizePolicy);
        objectPropertiesWindow->setMinimumSize(QSize(183, 227));
        objectPropertiesWindow->setMaximumSize(QSize(183, 227));
        buttonBox = new QDialogButtonBox(objectPropertiesWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(10, 190, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        layoutWidget_3 = new QWidget(objectPropertiesWindow);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 40, 166, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelR_2 = new QLabel(layoutWidget_3);
        labelR_2->setObjectName(QStringLiteral("labelR_2"));
        labelR_2->setMaximumSize(QSize(13, 22));

        horizontalLayout_3->addWidget(labelR_2);

        editR = new QLineEdit(layoutWidget_3);
        editR->setObjectName(QStringLiteral("editR"));
        editR->setMaximumSize(QSize(30, 22));
        editR->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        horizontalLayout_3->addWidget(editR);

        labelG_2 = new QLabel(layoutWidget_3);
        labelG_2->setObjectName(QStringLiteral("labelG_2"));
        labelG_2->setMaximumSize(QSize(13, 22));

        horizontalLayout_3->addWidget(labelG_2);

        editG = new QLineEdit(layoutWidget_3);
        editG->setObjectName(QStringLiteral("editG"));
        editG->setMaximumSize(QSize(30, 22));
        editG->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        horizontalLayout_3->addWidget(editG);

        labelB_2 = new QLabel(layoutWidget_3);
        labelB_2->setObjectName(QStringLiteral("labelB_2"));
        labelB_2->setMaximumSize(QSize(12, 22));

        horizontalLayout_3->addWidget(labelB_2);

        editB = new QLineEdit(layoutWidget_3);
        editB->setObjectName(QStringLiteral("editB"));
        editB->setMaximumSize(QSize(30, 22));
        editB->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        horizontalLayout_3->addWidget(editB);

        typesOfObjects = new QComboBox(objectPropertiesWindow);
        typesOfObjects->setObjectName(QStringLiteral("typesOfObjects"));
        typesOfObjects->setGeometry(QRect(10, 5, 86, 26));
        editID = new QLineEdit(objectPropertiesWindow);
        editID->setObjectName(QStringLiteral("editID"));
        editID->setGeometry(QRect(130, 10, 46, 22));
        editID->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);
        label_5 = new QLabel(objectPropertiesWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(105, 10, 26, 16));
        layoutWidget_2 = new QWidget(objectPropertiesWindow);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 75, 166, 111));
        formLayout = new QFormLayout(layoutWidget_2);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelX1 = new QLabel(layoutWidget_2);
        labelX1->setObjectName(QStringLiteral("labelX1"));
        labelX1->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelX1);

        editX1 = new QLineEdit(layoutWidget_2);
        editX1->setObjectName(QStringLiteral("editX1"));
        editX1->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        formLayout->setWidget(0, QFormLayout::FieldRole, editX1);

        labelY1 = new QLabel(layoutWidget_2);
        labelY1->setObjectName(QStringLiteral("labelY1"));
        labelY1->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelY1);

        editY1 = new QLineEdit(layoutWidget_2);
        editY1->setObjectName(QStringLiteral("editY1"));
        editY1->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        formLayout->setWidget(1, QFormLayout::FieldRole, editY1);

        labelX2 = new QLabel(layoutWidget_2);
        labelX2->setObjectName(QStringLiteral("labelX2"));
        labelX2->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelX2);

        editX2 = new QLineEdit(layoutWidget_2);
        editX2->setObjectName(QStringLiteral("editX2"));
        editX2->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        formLayout->setWidget(2, QFormLayout::FieldRole, editX2);

        labelY2 = new QLabel(layoutWidget_2);
        labelY2->setObjectName(QStringLiteral("labelY2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelY2);

        editY2 = new QLineEdit(layoutWidget_2);
        editY2->setObjectName(QStringLiteral("editY2"));
        editY2->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        formLayout->setWidget(3, QFormLayout::FieldRole, editY2);


        retranslateUi(objectPropertiesWindow);
        QObject::connect(buttonBox, SIGNAL(rejected()), objectPropertiesWindow, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), objectPropertiesWindow, SLOT(accept()));

        QMetaObject::connectSlotsByName(objectPropertiesWindow);
    } // setupUi

    void retranslateUi(QDialog *objectPropertiesWindow)
    {
        objectPropertiesWindow->setWindowTitle(QApplication::translate("objectPropertiesWindow", "Add", 0));
        labelR_2->setText(QApplication::translate("objectPropertiesWindow", "R:", 0));
        editR->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "R", 0));
        labelG_2->setText(QApplication::translate("objectPropertiesWindow", "G:", 0));
        editG->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "G", 0));
        labelB_2->setText(QApplication::translate("objectPropertiesWindow", "B:", 0));
        editB->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "B", 0));
        typesOfObjects->clear();
        typesOfObjects->insertItems(0, QStringList()
         << QApplication::translate("objectPropertiesWindow", "Point", 0)
         << QApplication::translate("objectPropertiesWindow", "Segment", 0)
         << QApplication::translate("objectPropertiesWindow", "Circle", 0)
        );
        editID->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "ID", 0));
        label_5->setText(QApplication::translate("objectPropertiesWindow", "ID:", 0));
        labelX1->setText(QApplication::translate("objectPropertiesWindow", "X:", 0));
        editX1->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "X:", 0));
        labelY1->setText(QApplication::translate("objectPropertiesWindow", "Y:", 0));
        editY1->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "Y:", 0));
        labelX2->setText(QApplication::translate("objectPropertiesWindow", "X2:", 0));
        editX2->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "X:", 0));
        labelY2->setText(QApplication::translate("objectPropertiesWindow", "Y2:", 0));
        editY2->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "Y:", 0));
    } // retranslateUi

};

namespace Ui {
    class objectPropertiesWindow: public Ui_objectPropertiesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTPROPERTIESWINDOW_H
