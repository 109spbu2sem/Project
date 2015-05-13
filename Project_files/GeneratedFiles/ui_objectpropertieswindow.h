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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_objectPropertiesWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QComboBox *typesOfObjects;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QLineEdit *editID;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelR_2;
    QLineEdit *editR;
    QLabel *labelG_2;
    QLineEdit *editG;
    QLabel *labelB_2;
    QLineEdit *editB;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *X1layout;
    QLabel *labelX1;
    QLineEdit *editX1;
    QCheckBox *checkX1;
    QHBoxLayout *Y1layout;
    QLabel *labelY1;
    QLineEdit *editY1;
    QCheckBox *checkY1;
    QHBoxLayout *X2layout;
    QLabel *labelX2;
    QLineEdit *editX2;
    QCheckBox *checkX2;
    QHBoxLayout *Y2layout;
    QLabel *labelY2;
    QLineEdit *editY2;
    QCheckBox *checkY2;
    QDialogButtonBox *buttonBox;

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
        objectPropertiesWindow->setMaximumSize(QSize(281, 227));
        verticalLayout_2 = new QVBoxLayout(objectPropertiesWindow);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        typesOfObjects = new QComboBox(objectPropertiesWindow);
        typesOfObjects->setObjectName(QStringLiteral("typesOfObjects"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(typesOfObjects->sizePolicy().hasHeightForWidth());
        typesOfObjects->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(typesOfObjects);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_5 = new QLabel(objectPropertiesWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_5);

        editID = new QLineEdit(objectPropertiesWindow);
        editID->setObjectName(QStringLiteral("editID"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(editID->sizePolicy().hasHeightForWidth());
        editID->setSizePolicy(sizePolicy2);
        editID->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        horizontalLayout->addWidget(editID);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        labelR_2 = new QLabel(objectPropertiesWindow);
        labelR_2->setObjectName(QStringLiteral("labelR_2"));
        labelR_2->setMaximumSize(QSize(13, 22));

        horizontalLayout_3->addWidget(labelR_2);

        editR = new QLineEdit(objectPropertiesWindow);
        editR->setObjectName(QStringLiteral("editR"));
        editR->setMaximumSize(QSize(30, 22));
        editR->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        horizontalLayout_3->addWidget(editR);

        labelG_2 = new QLabel(objectPropertiesWindow);
        labelG_2->setObjectName(QStringLiteral("labelG_2"));
        labelG_2->setMaximumSize(QSize(13, 22));

        horizontalLayout_3->addWidget(labelG_2);

        editG = new QLineEdit(objectPropertiesWindow);
        editG->setObjectName(QStringLiteral("editG"));
        editG->setMaximumSize(QSize(30, 22));
        editG->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        horizontalLayout_3->addWidget(editG);

        labelB_2 = new QLabel(objectPropertiesWindow);
        labelB_2->setObjectName(QStringLiteral("labelB_2"));
        labelB_2->setMaximumSize(QSize(12, 22));

        horizontalLayout_3->addWidget(labelB_2);

        editB = new QLineEdit(objectPropertiesWindow);
        editB->setObjectName(QStringLiteral("editB"));
        editB->setMaximumSize(QSize(30, 22));
        editB->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        horizontalLayout_3->addWidget(editB);


        verticalLayout_2->addLayout(horizontalLayout_3);

        frame = new QFrame(objectPropertiesWindow);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        X1layout = new QHBoxLayout();
        X1layout->setObjectName(QStringLiteral("X1layout"));
        labelX1 = new QLabel(frame);
        labelX1->setObjectName(QStringLiteral("labelX1"));
        labelX1->setLayoutDirection(Qt::RightToLeft);

        X1layout->addWidget(labelX1);

        editX1 = new QLineEdit(frame);
        editX1->setObjectName(QStringLiteral("editX1"));
        editX1->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        X1layout->addWidget(editX1);

        checkX1 = new QCheckBox(frame);
        checkX1->setObjectName(QStringLiteral("checkX1"));

        X1layout->addWidget(checkX1);


        verticalLayout->addLayout(X1layout);

        Y1layout = new QHBoxLayout();
        Y1layout->setObjectName(QStringLiteral("Y1layout"));
        labelY1 = new QLabel(frame);
        labelY1->setObjectName(QStringLiteral("labelY1"));
        labelY1->setLayoutDirection(Qt::RightToLeft);

        Y1layout->addWidget(labelY1);

        editY1 = new QLineEdit(frame);
        editY1->setObjectName(QStringLiteral("editY1"));
        editY1->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        Y1layout->addWidget(editY1);

        checkY1 = new QCheckBox(frame);
        checkY1->setObjectName(QStringLiteral("checkY1"));

        Y1layout->addWidget(checkY1);


        verticalLayout->addLayout(Y1layout);

        X2layout = new QHBoxLayout();
        X2layout->setObjectName(QStringLiteral("X2layout"));
        labelX2 = new QLabel(frame);
        labelX2->setObjectName(QStringLiteral("labelX2"));
        labelX2->setLayoutDirection(Qt::RightToLeft);

        X2layout->addWidget(labelX2);

        editX2 = new QLineEdit(frame);
        editX2->setObjectName(QStringLiteral("editX2"));
        editX2->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        X2layout->addWidget(editX2);

        checkX2 = new QCheckBox(frame);
        checkX2->setObjectName(QStringLiteral("checkX2"));

        X2layout->addWidget(checkX2);


        verticalLayout->addLayout(X2layout);

        Y2layout = new QHBoxLayout();
        Y2layout->setObjectName(QStringLiteral("Y2layout"));
        labelY2 = new QLabel(frame);
        labelY2->setObjectName(QStringLiteral("labelY2"));

        Y2layout->addWidget(labelY2);

        editY2 = new QLineEdit(frame);
        editY2->setObjectName(QStringLiteral("editY2"));
        editY2->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhFormattedNumbersOnly);

        Y2layout->addWidget(editY2);

        checkY2 = new QCheckBox(frame);
        checkY2->setObjectName(QStringLiteral("checkY2"));

        Y2layout->addWidget(checkY2);


        verticalLayout->addLayout(Y2layout);


        verticalLayout_2->addWidget(frame);

        buttonBox = new QDialogButtonBox(objectPropertiesWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        verticalLayout_2->addWidget(buttonBox);

        QWidget::setTabOrder(editX1, editY1);
        QWidget::setTabOrder(editY1, editX2);
        QWidget::setTabOrder(editX2, editY2);
        QWidget::setTabOrder(editY2, checkX1);
        QWidget::setTabOrder(checkX1, checkY1);
        QWidget::setTabOrder(checkY1, checkX2);
        QWidget::setTabOrder(checkX2, checkY2);
        QWidget::setTabOrder(checkY2, typesOfObjects);
        QWidget::setTabOrder(typesOfObjects, editR);
        QWidget::setTabOrder(editR, editG);
        QWidget::setTabOrder(editG, editB);
        QWidget::setTabOrder(editB, editID);

        retranslateUi(objectPropertiesWindow);
        QObject::connect(buttonBox, SIGNAL(rejected()), objectPropertiesWindow, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), objectPropertiesWindow, SLOT(accept()));

        QMetaObject::connectSlotsByName(objectPropertiesWindow);
    } // setupUi

    void retranslateUi(QDialog *objectPropertiesWindow)
    {
        objectPropertiesWindow->setWindowTitle(QApplication::translate("objectPropertiesWindow", "Add", 0));
        typesOfObjects->clear();
        typesOfObjects->insertItems(0, QStringList()
         << QApplication::translate("objectPropertiesWindow", "Point", 0)
         << QApplication::translate("objectPropertiesWindow", "Segment", 0)
         << QApplication::translate("objectPropertiesWindow", "Circle", 0)
        );
        label_5->setText(QApplication::translate("objectPropertiesWindow", "ID:", 0));
        editID->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "ID", 0));
        labelR_2->setText(QApplication::translate("objectPropertiesWindow", "R:", 0));
        editR->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "R", 0));
        labelG_2->setText(QApplication::translate("objectPropertiesWindow", "G:", 0));
        editG->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "G", 0));
        labelB_2->setText(QApplication::translate("objectPropertiesWindow", "B:", 0));
        editB->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "B", 0));
        labelX1->setText(QApplication::translate("objectPropertiesWindow", "X:", 0));
        editX1->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "X:", 0));
#ifndef QT_NO_TOOLTIP
        checkX1->setToolTip(QApplication::translate("objectPropertiesWindow", "Is constant?", 0));
#endif // QT_NO_TOOLTIP
        checkX1->setText(QString());
        labelY1->setText(QApplication::translate("objectPropertiesWindow", "Y:", 0));
        editY1->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "Y:", 0));
#ifndef QT_NO_TOOLTIP
        checkY1->setToolTip(QApplication::translate("objectPropertiesWindow", "Is constant?", 0));
#endif // QT_NO_TOOLTIP
        checkY1->setText(QString());
        labelX2->setText(QApplication::translate("objectPropertiesWindow", "X2:", 0));
        editX2->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "X:", 0));
#ifndef QT_NO_TOOLTIP
        checkX2->setToolTip(QApplication::translate("objectPropertiesWindow", "Is constant?", 0));
#endif // QT_NO_TOOLTIP
        checkX2->setText(QString());
        labelY2->setText(QApplication::translate("objectPropertiesWindow", "Y2:", 0));
        editY2->setPlaceholderText(QApplication::translate("objectPropertiesWindow", "Y:", 0));
#ifndef QT_NO_TOOLTIP
        checkY2->setToolTip(QApplication::translate("objectPropertiesWindow", "Is constant?", 0));
#endif // QT_NO_TOOLTIP
        checkY2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class objectPropertiesWindow: public Ui_objectPropertiesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTPROPERTIESWINDOW_H
