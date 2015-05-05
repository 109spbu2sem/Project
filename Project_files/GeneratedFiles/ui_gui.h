/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mycanvas.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    MyCanvas *graphicsView;
    QPushButton *openAddingBTN;
    QGroupBox *groupBox;
    QComboBox *typesOfObjects;
    QPushButton *addBTN;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *labelX1;
    QLineEdit *editX1;
    QLabel *labelY1;
    QLineEdit *editY1;
    QLabel *labelX2;
    QLineEdit *editX2;
    QLabel *labelY2;
    QLineEdit *editY2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelR;
    QLineEdit *editR;
    QLabel *labelG;
    QLineEdit *editG;
    QLabel *labelB;
    QLineEdit *editB;
    QGroupBox *groupBox_2;
    QComboBox *ruleBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *ruleValueLabel;
    QLineEdit *ruleValueEdit;
    QPushButton *pushButton;
    QPushButton *calculateBTN;
    QTableWidget *objectsList;
    QPushButton *pushButton_2;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout;
    QRadioButton *selectTool;
    QRadioButton *pointTool;
    QRadioButton *segmentTool;
    QRadioButton *circleTool;
    QRadioButton *zoomPlusTool;
    QRadioButton *zoomMinusTool;
    QPushButton *concatinateBTN;
    QPushButton *saveButton;
    QPushButton *saveAsButton;
    QPushButton *loadButton;
    QPushButton *deleteAllBTN;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1084, 617);
        MainWindow->setMinimumSize(QSize(1084, 617));
        MainWindow->setMaximumSize(QSize(1084, 617));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(225, 225, 225, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new MyCanvas(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(350, 5, 731, 591));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        openAddingBTN = new QPushButton(centralWidget);
        openAddingBTN->setObjectName(QStringLiteral("openAddingBTN"));
        openAddingBTN->setGeometry(QRect(5, 370, 61, 28));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 196, 221));
        typesOfObjects = new QComboBox(groupBox);
        typesOfObjects->setObjectName(QStringLiteral("typesOfObjects"));
        typesOfObjects->setGeometry(QRect(15, 20, 86, 26));
        addBTN = new QPushButton(groupBox);
        addBTN->setObjectName(QStringLiteral("addBTN"));
        addBTN->setGeometry(QRect(110, 20, 76, 28));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(15, 90, 166, 111));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelX1 = new QLabel(layoutWidget);
        labelX1->setObjectName(QStringLiteral("labelX1"));
        labelX1->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelX1);

        editX1 = new QLineEdit(layoutWidget);
        editX1->setObjectName(QStringLiteral("editX1"));

        formLayout->setWidget(0, QFormLayout::FieldRole, editX1);

        labelY1 = new QLabel(layoutWidget);
        labelY1->setObjectName(QStringLiteral("labelY1"));
        labelY1->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelY1);

        editY1 = new QLineEdit(layoutWidget);
        editY1->setObjectName(QStringLiteral("editY1"));

        formLayout->setWidget(1, QFormLayout::FieldRole, editY1);

        labelX2 = new QLabel(layoutWidget);
        labelX2->setObjectName(QStringLiteral("labelX2"));
        labelX2->setLayoutDirection(Qt::RightToLeft);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelX2);

        editX2 = new QLineEdit(layoutWidget);
        editX2->setObjectName(QStringLiteral("editX2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, editX2);

        labelY2 = new QLabel(layoutWidget);
        labelY2->setObjectName(QStringLiteral("labelY2"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelY2);

        editY2 = new QLineEdit(layoutWidget);
        editY2->setObjectName(QStringLiteral("editY2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, editY2);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(15, 55, 166, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelR = new QLabel(layoutWidget1);
        labelR->setObjectName(QStringLiteral("labelR"));
        labelR->setMaximumSize(QSize(13, 22));

        horizontalLayout_2->addWidget(labelR);

        editR = new QLineEdit(layoutWidget1);
        editR->setObjectName(QStringLiteral("editR"));
        editR->setMaximumSize(QSize(30, 22));

        horizontalLayout_2->addWidget(editR);

        labelG = new QLabel(layoutWidget1);
        labelG->setObjectName(QStringLiteral("labelG"));
        labelG->setMaximumSize(QSize(13, 22));

        horizontalLayout_2->addWidget(labelG);

        editG = new QLineEdit(layoutWidget1);
        editG->setObjectName(QStringLiteral("editG"));
        editG->setMaximumSize(QSize(30, 22));

        horizontalLayout_2->addWidget(editG);

        labelB = new QLabel(layoutWidget1);
        labelB->setObjectName(QStringLiteral("labelB"));
        labelB->setMaximumSize(QSize(12, 22));

        horizontalLayout_2->addWidget(labelB);

        editB = new QLineEdit(layoutWidget1);
        editB->setObjectName(QStringLiteral("editB"));
        editB->setMaximumSize(QSize(30, 22));

        horizontalLayout_2->addWidget(editB);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 270, 226, 86));
        ruleBox = new QComboBox(groupBox_2);
        ruleBox->setObjectName(QStringLiteral("ruleBox"));
        ruleBox->setGeometry(QRect(10, 20, 206, 22));
        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 50, 213, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ruleValueLabel = new QLabel(layoutWidget2);
        ruleValueLabel->setObjectName(QStringLiteral("ruleValueLabel"));

        horizontalLayout->addWidget(ruleValueLabel);

        ruleValueEdit = new QLineEdit(layoutWidget2);
        ruleValueEdit->setObjectName(QStringLiteral("ruleValueEdit"));

        horizontalLayout->addWidget(ruleValueEdit);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        calculateBTN = new QPushButton(centralWidget);
        calculateBTN->setObjectName(QStringLiteral("calculateBTN"));
        calculateBTN->setGeometry(QRect(70, 370, 101, 28));
        objectsList = new QTableWidget(centralWidget);
        objectsList->setObjectName(QStringLiteral("objectsList"));
        objectsList->setGeometry(QRect(5, 400, 236, 192));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(245, 165, 101, 28));
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(265, 5, 81, 157));
        verticalLayout = new QVBoxLayout(layoutWidget3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        selectTool = new QRadioButton(layoutWidget3);
        selectTool->setObjectName(QStringLiteral("selectTool"));
        selectTool->setLayoutDirection(Qt::RightToLeft);
        selectTool->setChecked(true);

        verticalLayout->addWidget(selectTool);

        pointTool = new QRadioButton(layoutWidget3);
        pointTool->setObjectName(QStringLiteral("pointTool"));
        pointTool->setLayoutDirection(Qt::RightToLeft);

        verticalLayout->addWidget(pointTool);

        segmentTool = new QRadioButton(layoutWidget3);
        segmentTool->setObjectName(QStringLiteral("segmentTool"));
        segmentTool->setLayoutDirection(Qt::RightToLeft);
        segmentTool->setCheckable(false);

        verticalLayout->addWidget(segmentTool);

        circleTool = new QRadioButton(layoutWidget3);
        circleTool->setObjectName(QStringLiteral("circleTool"));
        circleTool->setLayoutDirection(Qt::RightToLeft);
        circleTool->setCheckable(false);

        verticalLayout->addWidget(circleTool);

        zoomPlusTool = new QRadioButton(layoutWidget3);
        zoomPlusTool->setObjectName(QStringLiteral("zoomPlusTool"));
        zoomPlusTool->setLayoutDirection(Qt::RightToLeft);

        verticalLayout->addWidget(zoomPlusTool);

        zoomMinusTool = new QRadioButton(layoutWidget3);
        zoomMinusTool->setObjectName(QStringLiteral("zoomMinusTool"));
        zoomMinusTool->setLayoutDirection(Qt::RightToLeft);

        verticalLayout->addWidget(zoomMinusTool);

        concatinateBTN = new QPushButton(centralWidget);
        concatinateBTN->setObjectName(QStringLiteral("concatinateBTN"));
        concatinateBTN->setGeometry(QRect(225, 200, 121, 28));
        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(5, 10, 75, 23));
        saveAsButton = new QPushButton(centralWidget);
        saveAsButton->setObjectName(QStringLiteral("saveAsButton"));
        saveAsButton->setGeometry(QRect(85, 10, 75, 23));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(170, 10, 75, 23));
        deleteAllBTN = new QPushButton(centralWidget);
        deleteAllBTN->setObjectName(QStringLiteral("deleteAllBTN"));
        deleteAllBTN->setGeometry(QRect(175, 370, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1084, 26));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Painter", 0));
        openAddingBTN->setText(QApplication::translate("MainWindow", "Adding Window", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Add Object", 0));
        typesOfObjects->clear();
        typesOfObjects->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Point", 0)
         << QApplication::translate("MainWindow", "Segment", 0)
         << QApplication::translate("MainWindow", "Circle", 0)
        );
        addBTN->setText(QApplication::translate("MainWindow", "Add", 0));
        labelX1->setText(QApplication::translate("MainWindow", "X:", 0));
        editX1->setPlaceholderText(QApplication::translate("MainWindow", "X:", 0));
        labelY1->setText(QApplication::translate("MainWindow", "Y:", 0));
        editY1->setPlaceholderText(QApplication::translate("MainWindow", "Y:", 0));
        labelX2->setText(QApplication::translate("MainWindow", "X2:", 0));
        editX2->setPlaceholderText(QApplication::translate("MainWindow", "X:", 0));
        labelY2->setText(QApplication::translate("MainWindow", "Y2:", 0));
        editY2->setPlaceholderText(QApplication::translate("MainWindow", "Y:", 0));
        labelR->setText(QApplication::translate("MainWindow", "R:", 0));
        editR->setPlaceholderText(QApplication::translate("MainWindow", "R", 0));
        labelG->setText(QApplication::translate("MainWindow", "G:", 0));
        editG->setPlaceholderText(QApplication::translate("MainWindow", "G", 0));
        labelB->setText(QApplication::translate("MainWindow", "B:", 0));
        editB->setPlaceholderText(QApplication::translate("MainWindow", "B", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Add Rule", 0));
        ruleBox->clear();
        ruleBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Distance from point to point", 0)
         << QApplication::translate("MainWindow", "Distance from point to line", 0)
         << QApplication::translate("MainWindow", "Three points on line", 0)
         << QApplication::translate("MainWindow", "Ratio between three points", 0)
         << QApplication::translate("MainWindow", "Angle", 0)
        );
        ruleValueLabel->setText(QApplication::translate("MainWindow", "Value: ", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Add", 0));
        calculateBTN->setText(QApplication::translate("MainWindow", "Redraw", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Clear selection", 0));
        selectTool->setText(QApplication::translate("MainWindow", "Select", 0));
        pointTool->setText(QApplication::translate("MainWindow", "Point", 0));
        segmentTool->setText(QApplication::translate("MainWindow", "Segment", 0));
        circleTool->setText(QApplication::translate("MainWindow", "Circle", 0));
        zoomPlusTool->setText(QApplication::translate("MainWindow", "Zoom+", 0));
        zoomMinusTool->setText(QApplication::translate("MainWindow", "Zoom-", 0));
        concatinateBTN->setText(QApplication::translate("MainWindow", "Concatenate points", 0));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0));
        saveAsButton->setText(QApplication::translate("MainWindow", "Save as...", 0));
        loadButton->setText(QApplication::translate("MainWindow", "Load", 0));
        deleteAllBTN->setText(QApplication::translate("MainWindow", "Delete All", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
