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
#include <QtWidgets/QFrame>
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mycanvas.h"

QT_BEGIN_NAMESPACE

class Ui_GUI
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionClose;
    QAction *actionRedraw_all;
    QAction *actionClear_all;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *concatinateBTN;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QComboBox *ruleBox;
    QHBoxLayout *horizontalLayout;
    QLabel *ruleValueLabel;
    QLineEdit *ruleValueEdit;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QPushButton *selectBTNTool;
    QPushButton *pointBTNTool;
    QPushButton *ZoomBTNTool;
    QSpacerItem *verticalSpacer;
    QSplitter *splitter_2;
    MyCanvas *graphicsView;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout_8;
    QListWidget *propertiesList;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_7;
    QListWidget *objectsList;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *openAddingBTN;
    QPushButton *pushButton_5;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_6;
    QListWidget *rulesList;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *statusBar;
    QLabel *messageBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOptions;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(953, 692);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionRedraw_all = new QAction(MainWindow);
        actionRedraw_all->setObjectName(QStringLiteral("actionRedraw_all"));
        actionClear_all = new QAction(MainWindow);
        actionClear_all->setObjectName(QStringLiteral("actionClear_all"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(5, 1, 1, 1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        concatinateBTN = new QPushButton(centralWidget);
        concatinateBTN->setObjectName(QStringLiteral("concatinateBTN"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(concatinateBTN->sizePolicy().hasHeightForWidth());
        concatinateBTN->setSizePolicy(sizePolicy1);
        concatinateBTN->setMinimumSize(QSize(100, 28));
        concatinateBTN->setMaximumSize(QSize(100, 28));

        verticalLayout->addWidget(concatinateBTN);


        horizontalLayout_2->addLayout(verticalLayout);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setMinimumSize(QSize(0, 0));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(3);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(1, 1, 1, 1);
        ruleBox = new QComboBox(groupBox_2);
        ruleBox->setObjectName(QStringLiteral("ruleBox"));

        verticalLayout_5->addWidget(ruleBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ruleValueLabel = new QLabel(groupBox_2);
        ruleValueLabel->setObjectName(QStringLiteral("ruleValueLabel"));

        horizontalLayout->addWidget(ruleValueLabel);

        ruleValueEdit = new QLineEdit(groupBox_2);
        ruleValueEdit->setObjectName(QStringLiteral("ruleValueEdit"));

        horizontalLayout->addWidget(ruleValueEdit);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        pushButton->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_5->addLayout(horizontalLayout);


        horizontalLayout_2->addWidget(groupBox_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame);
        horizontalLayout_7->setSpacing(3);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(1, 1, 1, 1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        selectBTNTool = new QPushButton(frame);
        selectBTNTool->setObjectName(QStringLiteral("selectBTNTool"));
        sizePolicy1.setHeightForWidth(selectBTNTool->sizePolicy().hasHeightForWidth());
        selectBTNTool->setSizePolicy(sizePolicy1);
        selectBTNTool->setMinimumSize(QSize(29, 28));
        selectBTNTool->setMaximumSize(QSize(29, 29));
        selectBTNTool->setCheckable(true);
        selectBTNTool->setChecked(true);

        verticalLayout_2->addWidget(selectBTNTool);

        pointBTNTool = new QPushButton(frame);
        pointBTNTool->setObjectName(QStringLiteral("pointBTNTool"));
        sizePolicy1.setHeightForWidth(pointBTNTool->sizePolicy().hasHeightForWidth());
        pointBTNTool->setSizePolicy(sizePolicy1);
        pointBTNTool->setMinimumSize(QSize(29, 29));
        pointBTNTool->setMaximumSize(QSize(29, 29));
        QIcon icon;
        icon.addFile(QStringLiteral("icons/pointbtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        pointBTNTool->setIcon(icon);
        pointBTNTool->setCheckable(true);

        verticalLayout_2->addWidget(pointBTNTool);

        ZoomBTNTool = new QPushButton(frame);
        ZoomBTNTool->setObjectName(QStringLiteral("ZoomBTNTool"));
        sizePolicy1.setHeightForWidth(ZoomBTNTool->sizePolicy().hasHeightForWidth());
        ZoomBTNTool->setSizePolicy(sizePolicy1);
        ZoomBTNTool->setMinimumSize(QSize(29, 28));
        ZoomBTNTool->setMaximumSize(QSize(29, 29));
        ZoomBTNTool->setCheckable(true);

        verticalLayout_2->addWidget(ZoomBTNTool);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_7->addLayout(verticalLayout_2);

        splitter_2 = new QSplitter(frame);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setChildrenCollapsible(false);
        graphicsView = new MyCanvas(splitter_2);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        splitter_2->addWidget(graphicsView);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy4);
        splitter->setOrientation(Qt::Vertical);
        splitter->setChildrenCollapsible(false);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_8 = new QVBoxLayout(widget);
        verticalLayout_8->setSpacing(3);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        propertiesList = new QListWidget(widget);
        propertiesList->setObjectName(QStringLiteral("propertiesList"));
        propertiesList->setMinimumSize(QSize(0, 0));
        propertiesList->setMaximumSize(QSize(300, 16777215));

        verticalLayout_8->addWidget(propertiesList);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(100, 28));

        horizontalLayout_8->addWidget(pushButton_3);


        verticalLayout_8->addLayout(horizontalLayout_8);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QStringLiteral("widget1"));
        verticalLayout_7 = new QVBoxLayout(widget1);
        verticalLayout_7->setSpacing(3);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        objectsList = new QListWidget(widget1);
        objectsList->setObjectName(QStringLiteral("objectsList"));
        objectsList->setMaximumSize(QSize(300, 16777215));
        objectsList->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
        objectsList->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout_7->addWidget(objectsList);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        openAddingBTN = new QPushButton(widget1);
        openAddingBTN->setObjectName(QStringLiteral("openAddingBTN"));
        sizePolicy1.setHeightForWidth(openAddingBTN->sizePolicy().hasHeightForWidth());
        openAddingBTN->setSizePolicy(sizePolicy1);
        openAddingBTN->setMinimumSize(QSize(100, 28));
        openAddingBTN->setMaximumSize(QSize(100, 28));

        horizontalLayout_6->addWidget(openAddingBTN);

        pushButton_5 = new QPushButton(widget1);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);
        pushButton_5->setMinimumSize(QSize(100, 28));
        pushButton_5->setMaximumSize(QSize(100, 28));

        horizontalLayout_6->addWidget(pushButton_5);


        verticalLayout_7->addLayout(horizontalLayout_6);

        splitter->addWidget(widget1);
        widget2 = new QWidget(splitter);
        widget2->setObjectName(QStringLiteral("widget2"));
        verticalLayout_6 = new QVBoxLayout(widget2);
        verticalLayout_6->setSpacing(3);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        rulesList = new QListWidget(widget2);
        rulesList->setObjectName(QStringLiteral("rulesList"));
        rulesList->setMaximumSize(QSize(300, 16777215));

        verticalLayout_6->addWidget(rulesList);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_2 = new QPushButton(widget2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(100, 28));

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(widget2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(100, 28));

        horizontalLayout_4->addWidget(pushButton_4);


        verticalLayout_6->addLayout(horizontalLayout_4);

        splitter->addWidget(widget2);
        splitter_2->addWidget(splitter);

        horizontalLayout_7->addWidget(splitter_2);

        splitter_2->raise();
        pushButton_3->raise();
        rulesList->raise();
        pushButton_5->raise();
        openAddingBTN->raise();
        splitter_2->raise();

        verticalLayout_3->addWidget(frame);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        statusBar = new QLabel(centralWidget);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        sizePolicy1.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy1);
        statusBar->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setPointSize(10);
        statusBar->setFont(font);

        horizontalLayout_3->addWidget(statusBar, 0, Qt::AlignLeft);

        messageBar = new QLabel(centralWidget);
        messageBar->setObjectName(QStringLiteral("messageBar"));
        sizePolicy2.setHeightForWidth(messageBar->sizePolicy().hasHeightForWidth());
        messageBar->setSizePolicy(sizePolicy2);
        messageBar->setMinimumSize(QSize(300, 0));
        messageBar->setFont(font);

        horizontalLayout_3->addWidget(messageBar);


        verticalLayout_3->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 953, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuOptions->addAction(actionRedraw_all);
        menuOptions->addAction(actionClear_all);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Painter", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0));
        actionRedraw_all->setText(QApplication::translate("MainWindow", "Redraw all", 0));
        actionClear_all->setText(QApplication::translate("MainWindow", "Clear all", 0));
        concatinateBTN->setText(QApplication::translate("MainWindow", "Create segment", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Add Rule", 0));
        ruleBox->clear();
        ruleBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Distance from point to point", 0)
         << QApplication::translate("MainWindow", "Distance from point to line", 0)
         << QApplication::translate("MainWindow", "Three points on line", 0)
         << QApplication::translate("MainWindow", "Ratio between three points", 0)
         << QApplication::translate("MainWindow", "Angle between segments", 0)
         << QApplication::translate("MainWindow", "External circle contact", 0)
         << QApplication::translate("MainWindow", "Internal circle contact", 0)
         << QApplication::translate("MainWindow", "Distance from point to segment", 0)
        );
        ruleValueLabel->setText(QApplication::translate("MainWindow", "Value: ", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Add", 0));
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
        pushButton_3->setText(QApplication::translate("MainWindow", "Change object", 0));
        openAddingBTN->setText(QApplication::translate("MainWindow", "Add object", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Delete objects", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Add rule", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Delete rule", 0));
        statusBar->setText(QApplication::translate("MainWindow", "Done", 0));
        messageBar->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0));
    } // retranslateUi

};

namespace Ui {
	class GUI : public Ui_GUI
	{
	};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
