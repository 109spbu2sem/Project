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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *textY1;
    QLineEdit *textX2;
    QLineEdit *textX1;
    QLineEdit *textY2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelR;
    QLineEdit *editR;
    QLabel *labelG;
    QLineEdit *editG;
    QLabel *labelB;
    QLineEdit *editB;
    QLabel *typeLabel;
    QLabel *idLabel;

    void setupUi(QDialog *objectPropertiesWindow)
    {
        if (objectPropertiesWindow->objectName().isEmpty())
            objectPropertiesWindow->setObjectName(QStringLiteral("objectPropertiesWindow"));
        objectPropertiesWindow->resize(208, 221);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(objectPropertiesWindow->sizePolicy().hasHeightForWidth());
        objectPropertiesWindow->setSizePolicy(sizePolicy);
        objectPropertiesWindow->setMinimumSize(QSize(208, 198));
        buttonBox = new QDialogButtonBox(objectPropertiesWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-1, 185, 201, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        label = new QLabel(objectPropertiesWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 70, 41, 16));
        label_2 = new QLabel(objectPropertiesWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 100, 41, 16));
        label_4 = new QLabel(objectPropertiesWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 155, 41, 16));
        label_3 = new QLabel(objectPropertiesWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(9, 125, 51, 16));
        textY1 = new QLineEdit(objectPropertiesWindow);
        textY1->setObjectName(QStringLiteral("textY1"));
        textY1->setGeometry(QRect(65, 97, 131, 22));
        textX2 = new QLineEdit(objectPropertiesWindow);
        textX2->setObjectName(QStringLiteral("textX2"));
        textX2->setEnabled(true);
        textX2->setGeometry(QRect(65, 126, 131, 22));
        textX2->setClearButtonEnabled(false);
        textX1 = new QLineEdit(objectPropertiesWindow);
        textX1->setObjectName(QStringLiteral("textX1"));
        textX1->setEnabled(true);
        textX1->setGeometry(QRect(65, 68, 131, 22));
        textY2 = new QLineEdit(objectPropertiesWindow);
        textY2->setObjectName(QStringLiteral("textY2"));
        textY2->setEnabled(true);
        textY2->setGeometry(QRect(65, 155, 131, 22));
        layoutWidget = new QWidget(objectPropertiesWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(5, 35, 166, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelR = new QLabel(layoutWidget);
        labelR->setObjectName(QStringLiteral("labelR"));
        labelR->setMaximumSize(QSize(13, 22));

        horizontalLayout_2->addWidget(labelR);

        editR = new QLineEdit(layoutWidget);
        editR->setObjectName(QStringLiteral("editR"));
        editR->setMaximumSize(QSize(30, 22));

        horizontalLayout_2->addWidget(editR);

        labelG = new QLabel(layoutWidget);
        labelG->setObjectName(QStringLiteral("labelG"));
        labelG->setMaximumSize(QSize(13, 22));

        horizontalLayout_2->addWidget(labelG);

        editG = new QLineEdit(layoutWidget);
        editG->setObjectName(QStringLiteral("editG"));
        editG->setMaximumSize(QSize(30, 22));

        horizontalLayout_2->addWidget(editG);

        labelB = new QLabel(layoutWidget);
        labelB->setObjectName(QStringLiteral("labelB"));
        labelB->setMaximumSize(QSize(12, 22));

        horizontalLayout_2->addWidget(labelB);

        editB = new QLineEdit(layoutWidget);
        editB->setObjectName(QStringLiteral("editB"));
        editB->setMaximumSize(QSize(30, 22));

        horizontalLayout_2->addWidget(editB);

        typeLabel = new QLabel(objectPropertiesWindow);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));
        typeLabel->setGeometry(QRect(105, 10, 91, 16));
        idLabel = new QLabel(objectPropertiesWindow);
        idLabel->setObjectName(QStringLiteral("idLabel"));
        idLabel->setGeometry(QRect(10, 10, 86, 16));

        retranslateUi(objectPropertiesWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), objectPropertiesWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), objectPropertiesWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(objectPropertiesWindow);
    } // setupUi

    void retranslateUi(QDialog *objectPropertiesWindow)
    {
        objectPropertiesWindow->setWindowTitle(QApplication::translate("objectPropertiesWindow", "Properties", 0));
        label->setText(QApplication::translate("objectPropertiesWindow", "X:", 0));
        label_2->setText(QApplication::translate("objectPropertiesWindow", "Y:", 0));
        label_4->setText(QApplication::translate("objectPropertiesWindow", "Y2:", 0));
        label_3->setText(QApplication::translate("objectPropertiesWindow", "X2:", 0));
        textY1->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "Y", 0));
        textX2->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "X", 0));
        textX1->setText(QString());
        textX1->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "X", 0));
        textY2->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "Y", 0));
        labelR->setText(QApplication::translate("objectPropertiesWindow", "R:", 0));
        editR->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "R", 0));
        labelG->setText(QApplication::translate("objectPropertiesWindow", "G:", 0));
        editG->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "G", 0));
        labelB->setText(QApplication::translate("objectPropertiesWindow", "B:", 0));
        editB->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "B", 0));
        typeLabel->setText(QApplication::translate("objectPropertiesWindow", "TYPE", 0));
        idLabel->setText(QApplication::translate("objectPropertiesWindow", "ID", 0));
    } // retranslateUi

};

namespace Ui {
    class objectPropertiesWindow: public Ui_objectPropertiesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTPROPERTIESWINDOW_H
