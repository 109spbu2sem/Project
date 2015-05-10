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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mycanvas.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionSave_As_2;
    QAction *actionExit;
    QAction *actionLoad;
    QAction *actionSave_2;
    QAction *actionSave_As_3;
    QAction *actionClose;
    QAction *actionRedraw_all;
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
    QLineEdit *editID;
    QLabel *label;
    QGroupBox *groupBox_2;
    QComboBox *ruleBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QLabel *ruleValueLabel;
    QLineEdit *ruleValueEdit;
    QPushButton *pushButton;
    QPushButton *calculateBTN;
    QListWidget *objectsList;
    QPushButton *pushButton_2;
    QPushButton *concatinateBTN;
    QPushButton *saveButton;
    QPushButton *saveAsButton;
    QPushButton *loadButton;
    QPushButton *deleteAllBTN;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *statusBar;
    QLabel *messageBar;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *selectBTNTool;
    QPushButton *pointBTNTool;
    QPushButton *ZoomBTNTool;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOptions;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1084, 655);
        MainWindow->setMinimumSize(QSize(1084, 628));
        MainWindow->setMaximumSize(QSize(1084, 655));
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionSave_As_2 = new QAction(MainWindow);
        actionSave_As_2->setObjectName(QStringLiteral("actionSave_As_2"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave_2 = new QAction(MainWindow);
        actionSave_2->setObjectName(QStringLiteral("actionSave_2"));
        actionSave_As_3 = new QAction(MainWindow);
        actionSave_As_3->setObjectName(QStringLiteral("actionSave_As_3"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionRedraw_all = new QAction(MainWindow);
        actionRedraw_all->setObjectName(QStringLiteral("actionRedraw_all"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new MyCanvas(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(350, 40, 731, 556));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        openAddingBTN = new QPushButton(centralWidget);
        openAddingBTN->setObjectName(QStringLiteral("openAddingBTN"));
        openAddingBTN->setGeometry(QRect(5, 370, 61, 28));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 196, 236));
        typesOfObjects = new QComboBox(groupBox);
        typesOfObjects->setObjectName(QStringLiteral("typesOfObjects"));
        typesOfObjects->setGeometry(QRect(15, 20, 86, 26));
        addBTN = new QPushButton(groupBox);
        addBTN->setObjectName(QStringLiteral("addBTN"));
        addBTN->setGeometry(QRect(105, 205, 76, 28));
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

        editID = new QLineEdit(groupBox);
        editID->setObjectName(QStringLiteral("editID"));
        editID->setGeometry(QRect(135, 25, 46, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 25, 26, 16));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 280, 226, 86));
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
        calculateBTN->setGeometry(QRect(840, 0, 101, 28));
        objectsList = new QListWidget(centralWidget);
        objectsList->setObjectName(QStringLiteral("objectsList"));
        objectsList->setGeometry(QRect(5, 400, 236, 192));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(245, 485, 101, 28));
        concatinateBTN = new QPushButton(centralWidget);
        concatinateBTN->setObjectName(QStringLiteral("concatinateBTN"));
        concatinateBTN->setGeometry(QRect(245, 520, 101, 28));
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
        deleteAllBTN->setGeometry(QRect(140, 370, 93, 28));
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(5, 600, 409, 23));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        statusBar = new QLabel(layoutWidget3);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setPointSize(10);
        statusBar->setFont(font);

        horizontalLayout_3->addWidget(statusBar, 0, Qt::AlignLeft);

        messageBar = new QLabel(layoutWidget3);
        messageBar->setObjectName(QStringLiteral("messageBar"));
        messageBar->setMinimumSize(QSize(300, 0));
        messageBar->setFont(font);

        horizontalLayout_3->addWidget(messageBar);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(210, 50, 31, 101));
        verticalLayout_2 = new QVBoxLayout(layoutWidget4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        selectBTNTool = new QPushButton(layoutWidget4);
        selectBTNTool->setObjectName(QStringLiteral("selectBTNTool"));
        selectBTNTool->setMaximumSize(QSize(29, 28));
        selectBTNTool->setCheckable(true);
        selectBTNTool->setChecked(true);

        verticalLayout_2->addWidget(selectBTNTool);

        pointBTNTool = new QPushButton(layoutWidget4);
        pointBTNTool->setObjectName(QStringLiteral("pointBTNTool"));
        pointBTNTool->setMaximumSize(QSize(29, 29));
        QIcon icon;
        icon.addFile(QStringLiteral("icons/pointbtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        pointBTNTool->setIcon(icon);
        pointBTNTool->setCheckable(true);

        verticalLayout_2->addWidget(pointBTNTool);

        ZoomBTNTool = new QPushButton(layoutWidget4);
        ZoomBTNTool->setObjectName(QStringLiteral("ZoomBTNTool"));
        ZoomBTNTool->setMaximumSize(QSize(29, 28));
        ZoomBTNTool->setCheckable(true);

        verticalLayout_2->addWidget(ZoomBTNTool);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1084, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave_2);
        menuFile->addAction(actionSave_As_3);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuOptions->addAction(actionRedraw_all);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Painter", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Load", 0));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave_As_2->setText(QApplication::translate("MainWindow", "Save As...", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave_2->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave_As_3->setText(QApplication::translate("MainWindow", "Save As", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        actionRedraw_all->setText(QApplication::translate("MainWindow", "Redraw all", 0));
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
        editID->setPlaceholderText(QApplication::translate("MainWindow", "ID", 0));
        label->setText(QApplication::translate("MainWindow", "ID:", 0));
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
        concatinateBTN->setText(QApplication::translate("MainWindow", "Concatenate points", 0));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0));
        saveAsButton->setText(QApplication::translate("MainWindow", "Save as...", 0));
        loadButton->setText(QApplication::translate("MainWindow", "Load", 0));
        deleteAllBTN->setText(QApplication::translate("MainWindow", "Delete All", 0));
        statusBar->setText(QApplication::translate("MainWindow", "Done", 0));
        messageBar->setText(QString());
#ifndef QT_NO_TOOLTIP
        selectBTNTool->setToolTip(QApplication::translate("MainWindow", "Select (Ctrl + 1)", 0));
#endif // QT_NO_TOOLTIP
        selectBTNTool->setText(QApplication::translate("MainWindow", "S", 0));
        selectBTNTool->setShortcut(QApplication::translate("MainWindow", "Ctrl+1", 0));
#ifndef QT_NO_TOOLTIP
        pointBTNTool->setToolTip(QApplication::translate("MainWindow", "Draw point (Ctrl + 2)", 0));
#endif // QT_NO_TOOLTIP
        pointBTNTool->setText(QString());
        pointBTNTool->setShortcut(QApplication::translate("MainWindow", "Ctrl+2", 0));
#ifndef QT_NO_TOOLTIP
        ZoomBTNTool->setToolTip(QApplication::translate("MainWindow", "Zoom+ (Ctrl + 5)", 0));
#endif // QT_NO_TOOLTIP
        ZoomBTNTool->setText(QApplication::translate("MainWindow", "Z", 0));
        ZoomBTNTool->setShortcut(QApplication::translate("MainWindow", "Ctrl+5", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
