/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *button9;
    QPushButton *button8;
    QPushButton *button7;
    QPushButton *buttonAdd;
    QPushButton *buttonSub;
    QPushButton *buttonMul;
    QPushButton *buttonDiv;
    QPushButton *buttonEqual;
    QPushButton *buttonClear;
    QPushButton *button4;
    QPushButton *button3;
    QPushButton *button2;
    QPushButton *button1;
    QPushButton *button6;
    QPushButton *button5;
    QPushButton *button0;
    QLineEdit *display;
    QMenuBar *menubar;
    QMenu *menuCalc;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 489);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        button9 = new QPushButton(centralwidget);
        button9->setObjectName("button9");
        button9->setGeometry(QRect(250, 310, 111, 61));
        button8 = new QPushButton(centralwidget);
        button8->setObjectName("button8");
        button8->setGeometry(QRect(130, 310, 111, 61));
        button7 = new QPushButton(centralwidget);
        button7->setObjectName("button7");
        button7->setGeometry(QRect(10, 310, 111, 61));
        buttonAdd = new QPushButton(centralwidget);
        buttonAdd->setObjectName("buttonAdd");
        buttonAdd->setGeometry(QRect(370, 170, 121, 61));
        buttonSub = new QPushButton(centralwidget);
        buttonSub->setObjectName("buttonSub");
        buttonSub->setGeometry(QRect(370, 240, 121, 61));
        buttonMul = new QPushButton(centralwidget);
        buttonMul->setObjectName("buttonMul");
        buttonMul->setGeometry(QRect(370, 380, 121, 61));
        buttonDiv = new QPushButton(centralwidget);
        buttonDiv->setObjectName("buttonDiv");
        buttonDiv->setGeometry(QRect(370, 310, 121, 61));
        buttonEqual = new QPushButton(centralwidget);
        buttonEqual->setObjectName("buttonEqual");
        buttonEqual->setGeometry(QRect(250, 380, 111, 61));
        buttonClear = new QPushButton(centralwidget);
        buttonClear->setObjectName("buttonClear");
        buttonClear->setGeometry(QRect(130, 380, 111, 61));
        button4 = new QPushButton(centralwidget);
        button4->setObjectName("button4");
        button4->setGeometry(QRect(10, 240, 111, 61));
        button3 = new QPushButton(centralwidget);
        button3->setObjectName("button3");
        button3->setGeometry(QRect(250, 170, 111, 61));
        button2 = new QPushButton(centralwidget);
        button2->setObjectName("button2");
        button2->setGeometry(QRect(130, 170, 111, 61));
        button1 = new QPushButton(centralwidget);
        button1->setObjectName("button1");
        button1->setGeometry(QRect(10, 170, 111, 61));
        button6 = new QPushButton(centralwidget);
        button6->setObjectName("button6");
        button6->setGeometry(QRect(250, 240, 111, 61));
        button5 = new QPushButton(centralwidget);
        button5->setObjectName("button5");
        button5->setGeometry(QRect(130, 240, 111, 61));
        button0 = new QPushButton(centralwidget);
        button0->setObjectName("button0");
        button0->setGeometry(QRect(10, 380, 111, 61));
        display = new QLineEdit(centralwidget);
        display->setObjectName("display");
        display->setGeometry(QRect(10, 10, 481, 151));
        display->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 21));
        menuCalc = new QMenu(menubar);
        menuCalc->setObjectName("menuCalc");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuCalc->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        button9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        button8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        button7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        buttonAdd->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        buttonSub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        buttonMul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        buttonDiv->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        buttonEqual->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        buttonClear->setText(QCoreApplication::translate("MainWindow", "CLEAR", nullptr));
        button4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        button3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        button2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        button1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        button6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        button5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        button0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        menuCalc->setTitle(QCoreApplication::translate("MainWindow", "Calc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
