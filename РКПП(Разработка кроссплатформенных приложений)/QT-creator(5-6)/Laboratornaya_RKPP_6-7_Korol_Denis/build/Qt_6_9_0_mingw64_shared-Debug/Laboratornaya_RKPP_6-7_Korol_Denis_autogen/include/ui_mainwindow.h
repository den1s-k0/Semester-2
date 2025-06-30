/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_3;
    QLabel *label_1_2;
    QLabel *label_1_1;
    QPushButton *pushButton_1_1;
    QTextEdit *textEdit_1_2;
    QTextEdit *textEdit_1_1;
    QWidget *page_2;
    QGridLayout *gridLayout_4;
    QTextEdit *textEdit_2_1;
    QLabel *label_2_1;
    QTextEdit *textEdit_2_2;
    QPushButton *pushButton_2_1;
    QTextEdit *textEdit_2_3;
    QLabel *label_2_3;
    QLabel *label_2_2;
    QWidget *page_6;
    QGridLayout *gridLayout_10;
    QLabel *label_5_4;
    QLabel *label_5_1;
    QTextEdit *textEdit_5_1;
    QLabel *label_5_3;
    QTextEdit *textEdit_5_4;
    QTextEdit *textEdit_5_2;
    QTextEdit *textEdit_5_3;
    QLabel *label_5_2;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_8;
    QStackedWidget *stackedWidget_2;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_7;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3_1;
    QFrame *line_2;
    QLabel *label_3_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3_3;
    QSpacerItem *verticalSpacer_3_1;
    QLabel *label_3_4;
    QWidget *page_4;
    QGridLayout *gridLayout_7;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_4_1;
    QFrame *line_3;
    QLabel *label_4_2;
    QLabel *label_4_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4_4;
    QSpacerItem *verticalSpacer;
    QLabel *label_4_5;
    QWidget *page_5;
    QGridLayout *gridLayout_9;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QGridLayout *gridLayout_11;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6_1;
    QFrame *line_4;
    QLabel *label_6_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6_4;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_6_3;
    QLabel *label_6_5;
    QWidget *widget;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_12;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 386, 537));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName("gridLayout_2");
        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout_2->addWidget(line, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName("checkBox");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(checkBox);

        comboBox = new QComboBox(scrollAreaWidgetContents);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(150, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(scrollAreaWidgetContents);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        gridLayout_3 = new QGridLayout(page);
        gridLayout_3->setObjectName("gridLayout_3");
        label_1_2 = new QLabel(page);
        label_1_2->setObjectName("label_1_2");

        gridLayout_3->addWidget(label_1_2, 3, 0, 1, 1);

        label_1_1 = new QLabel(page);
        label_1_1->setObjectName("label_1_1");

        gridLayout_3->addWidget(label_1_1, 1, 0, 1, 1);

        pushButton_1_1 = new QPushButton(page);
        pushButton_1_1->setObjectName("pushButton_1_1");

        gridLayout_3->addWidget(pushButton_1_1, 5, 0, 1, 1);

        textEdit_1_2 = new QTextEdit(page);
        textEdit_1_2->setObjectName("textEdit_1_2");

        gridLayout_3->addWidget(textEdit_1_2, 4, 0, 1, 1);

        textEdit_1_1 = new QTextEdit(page);
        textEdit_1_1->setObjectName("textEdit_1_1");

        gridLayout_3->addWidget(textEdit_1_1, 2, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        gridLayout_4 = new QGridLayout(page_2);
        gridLayout_4->setObjectName("gridLayout_4");
        textEdit_2_1 = new QTextEdit(page_2);
        textEdit_2_1->setObjectName("textEdit_2_1");

        gridLayout_4->addWidget(textEdit_2_1, 2, 0, 1, 1);

        label_2_1 = new QLabel(page_2);
        label_2_1->setObjectName("label_2_1");

        gridLayout_4->addWidget(label_2_1, 1, 0, 1, 1);

        textEdit_2_2 = new QTextEdit(page_2);
        textEdit_2_2->setObjectName("textEdit_2_2");

        gridLayout_4->addWidget(textEdit_2_2, 5, 0, 1, 1);

        pushButton_2_1 = new QPushButton(page_2);
        pushButton_2_1->setObjectName("pushButton_2_1");

        gridLayout_4->addWidget(pushButton_2_1, 8, 0, 1, 1);

        textEdit_2_3 = new QTextEdit(page_2);
        textEdit_2_3->setObjectName("textEdit_2_3");

        gridLayout_4->addWidget(textEdit_2_3, 7, 0, 1, 1);

        label_2_3 = new QLabel(page_2);
        label_2_3->setObjectName("label_2_3");

        gridLayout_4->addWidget(label_2_3, 6, 0, 1, 1);

        label_2_2 = new QLabel(page_2);
        label_2_2->setObjectName("label_2_2");

        gridLayout_4->addWidget(label_2_2, 4, 0, 1, 1);

        stackedWidget->addWidget(page_2);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        gridLayout_10 = new QGridLayout(page_6);
        gridLayout_10->setObjectName("gridLayout_10");
        label_5_4 = new QLabel(page_6);
        label_5_4->setObjectName("label_5_4");

        gridLayout_10->addWidget(label_5_4, 6, 0, 1, 1);

        label_5_1 = new QLabel(page_6);
        label_5_1->setObjectName("label_5_1");

        gridLayout_10->addWidget(label_5_1, 0, 0, 1, 1);

        textEdit_5_1 = new QTextEdit(page_6);
        textEdit_5_1->setObjectName("textEdit_5_1");

        gridLayout_10->addWidget(textEdit_5_1, 1, 0, 1, 1);

        label_5_3 = new QLabel(page_6);
        label_5_3->setObjectName("label_5_3");

        gridLayout_10->addWidget(label_5_3, 4, 0, 1, 1);

        textEdit_5_4 = new QTextEdit(page_6);
        textEdit_5_4->setObjectName("textEdit_5_4");

        gridLayout_10->addWidget(textEdit_5_4, 7, 0, 1, 1);

        textEdit_5_2 = new QTextEdit(page_6);
        textEdit_5_2->setObjectName("textEdit_5_2");

        gridLayout_10->addWidget(textEdit_5_2, 3, 0, 1, 1);

        textEdit_5_3 = new QTextEdit(page_6);
        textEdit_5_3->setObjectName("textEdit_5_3");

        gridLayout_10->addWidget(textEdit_5_3, 5, 0, 1, 1);

        label_5_2 = new QLabel(page_6);
        label_5_2->setObjectName("label_5_2");

        gridLayout_10->addWidget(label_5_2, 2, 0, 1, 1);

        pushButton = new QPushButton(page_6);
        pushButton->setObjectName("pushButton");

        gridLayout_10->addWidget(pushButton, 8, 0, 1, 1);

        stackedWidget->addWidget(page_6);

        gridLayout_2->addWidget(stackedWidget, 3, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        stackedWidget_2 = new QStackedWidget(centralwidget);
        stackedWidget_2->setObjectName("stackedWidget_2");
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        verticalLayout_7 = new QVBoxLayout(page_3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        scrollArea_2 = new QScrollArea(page_3);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 366, 311));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_5->setObjectName("gridLayout_5");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3_1 = new QLabel(scrollAreaWidgetContents_2);
        label_3_1->setObjectName("label_3_1");
        label_3_1->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        verticalLayout_2->addWidget(label_3_1);

        line_2 = new QFrame(scrollAreaWidgetContents_2);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_2->addWidget(line_2);

        label_3_2 = new QLabel(scrollAreaWidgetContents_2);
        label_3_2->setObjectName("label_3_2");
        label_3_2->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        verticalLayout_2->addWidget(label_3_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3_3 = new QLabel(scrollAreaWidgetContents_2);
        label_3_3->setObjectName("label_3_3");
        label_3_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(label_3_3);

        verticalSpacer_3_1 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3_1);


        horizontalLayout_2->addLayout(verticalLayout_3);

        label_3_4 = new QLabel(scrollAreaWidgetContents_2);
        label_3_4->setObjectName("label_3_4");
        label_3_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_3_4);


        gridLayout_5->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_7->addWidget(scrollArea_2);

        stackedWidget_2->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        gridLayout_7 = new QGridLayout(page_4);
        gridLayout_7->setObjectName("gridLayout_7");
        scrollArea_3 = new QScrollArea(page_4);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 366, 311));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_8->setObjectName("gridLayout_8");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_4_1 = new QLabel(scrollAreaWidgetContents_3);
        label_4_1->setObjectName("label_4_1");
        label_4_1->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        verticalLayout->addWidget(label_4_1);

        line_3 = new QFrame(scrollAreaWidgetContents_3);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line_3);

        label_4_2 = new QLabel(scrollAreaWidgetContents_3);
        label_4_2->setObjectName("label_4_2");
        label_4_2->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        verticalLayout->addWidget(label_4_2);


        horizontalLayout_3->addLayout(verticalLayout);

        label_4_3 = new QLabel(scrollAreaWidgetContents_3);
        label_4_3->setObjectName("label_4_3");
        label_4_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_4_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4_4 = new QLabel(scrollAreaWidgetContents_3);
        label_4_4->setObjectName("label_4_4");
        label_4_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_4_4);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_4);

        label_4_5 = new QLabel(scrollAreaWidgetContents_3);
        label_4_5->setObjectName("label_4_5");
        label_4_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_4_5);


        gridLayout_8->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        gridLayout_7->addWidget(scrollArea_3, 0, 0, 1, 1);

        stackedWidget_2->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        gridLayout_9 = new QGridLayout(page_5);
        gridLayout_9->setObjectName("gridLayout_9");
        scrollArea_4 = new QScrollArea(page_5);
        scrollArea_4->setObjectName("scrollArea_4");
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 366, 311));
        gridLayout_11 = new QGridLayout(scrollAreaWidgetContents_4);
        gridLayout_11->setObjectName("gridLayout_11");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_6_1 = new QLabel(scrollAreaWidgetContents_4);
        label_6_1->setObjectName("label_6_1");
        label_6_1->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        verticalLayout_5->addWidget(label_6_1);

        line_4 = new QFrame(scrollAreaWidgetContents_4);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_5->addWidget(line_4);

        label_6_2 = new QLabel(scrollAreaWidgetContents_4);
        label_6_2->setObjectName("label_6_2");
        label_6_2->setAlignment(Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        verticalLayout_5->addWidget(label_6_2);


        gridLayout_11->addLayout(verticalLayout_5, 0, 0, 2, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_6_4 = new QLabel(scrollAreaWidgetContents_4);
        label_6_4->setObjectName("label_6_4");
        label_6_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(label_6_4);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_2);


        gridLayout_11->addLayout(verticalLayout_6, 0, 2, 2, 1);

        label_6_3 = new QLabel(scrollAreaWidgetContents_4);
        label_6_3->setObjectName("label_6_3");
        label_6_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_11->addWidget(label_6_3, 0, 1, 2, 1);

        label_6_5 = new QLabel(scrollAreaWidgetContents_4);
        label_6_5->setObjectName("label_6_5");
        label_6_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_11->addWidget(label_6_5, 0, 3, 2, 1);

        scrollArea_4->setWidget(scrollAreaWidgetContents_4);

        gridLayout_9->addWidget(scrollArea_4, 0, 0, 1, 1);

        stackedWidget_2->addWidget(page_5);

        verticalLayout_8->addWidget(stackedWidget_2);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 200));
        gridLayout_6 = new QGridLayout(widget);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName("gridLayout_12");

        gridLayout_6->addLayout(gridLayout_12, 0, 0, 1, 1);


        verticalLayout_8->addWidget(widget);


        gridLayout->addLayout(verticalLayout_8, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_3);
        menu->addAction(action_2);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);
        stackedWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\201\321\202\320\276\320\275\320\260\321\205\320\276\320\266\320\264\320\265\320\275\320\270\320\265 \320\270\321\201\321\202\320\276\321\200\320\270\320\270", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\270\321\201\321\202\320\276\321\200\320\270\321\216", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214 \320\262 \321\204\320\260\320\271\320\273", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "A/BX", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "A/BX+C", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "A/B(X+D)+C", nullptr));

        label_1_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\203\321\216 \320\222:", nullptr));
        label_1_1->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\203\321\216 \320\220:", nullptr));
        pushButton_1_1->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        textEdit_1_1->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_2_1->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\203\321\216 \320\220:", nullptr));
        pushButton_2_1->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label_2_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\203\321\216 \320\241:", nullptr));
        label_2_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\203\321\216 \320\222:", nullptr));
        label_5_4->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\203\321\216 D:", nullptr));
        label_5_1->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\203\321\216 \320\220:", nullptr));
        label_5_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\203\321\216 \320\241:", nullptr));
        label_5_2->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\265\320\274\320\265\320\275\320\275\321\203\321\216 \320\222:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label_3_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:72pt;\">A</span></p></body></html>", nullptr));
        label_3_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:72pt;\">B*X</span></p></body></html>", nullptr));
        label_3_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:72pt;\">=</span></p></body></html>", nullptr));
        label_3_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:72pt;\">Y</span></p></body></html>", nullptr));
        label_4_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:48pt;\">A</span></p></body></html>", nullptr));
        label_4_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:48pt;\">B*X</span></p></body></html>", nullptr));
        label_4_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:48pt;\">+C</span></p></body></html>", nullptr));
        label_4_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:48pt;\">=</span></p></body></html>", nullptr));
        label_4_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:48pt;\">Y</span></p></body></html>", nullptr));
        label_6_1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:36pt;\">A</span></p></body></html>", nullptr));
        label_6_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:36pt;\">B*(X+D)</span></p></body></html>", nullptr));
        label_6_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:48pt;\">=</span></p></body></html>", nullptr));
        label_6_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:36pt;\">+C</span></p></body></html>", nullptr));
        label_6_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:36pt;\">Y</span></p></body></html>", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
