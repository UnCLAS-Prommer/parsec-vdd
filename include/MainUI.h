/********************************************************************************
** Form generated from reading UI file 'Main.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINUI_H
#define MAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *buttonsLayout;
    QPushButton *Add;
    QPushButton *Remove;
    QLabel *CounterTip;
    QLabel *Counter;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(351, 137);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 60, 301, 51));
        buttonsLayout = new QHBoxLayout(horizontalLayoutWidget);
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));
        buttonsLayout->setContentsMargins(0, 0, 0, 0);
        Add = new QPushButton(horizontalLayoutWidget);
        Add->setObjectName(QString::fromUtf8("Add"));
        QFont font;
        font.setFamily(QString::fromUtf8("Lucida Console"));
        font.setPointSize(10);
        Add->setFont(font);

        buttonsLayout->addWidget(Add);

        Remove = new QPushButton(horizontalLayoutWidget);
        Remove->setObjectName(QString::fromUtf8("Remove"));
        Remove->setFont(font);

        buttonsLayout->addWidget(Remove);

        CounterTip = new QLabel(centralwidget);
        CounterTip->setObjectName(QString::fromUtf8("CounterTip"));
        CounterTip->setGeometry(QRect(30, 20, 141, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        CounterTip->setFont(font1);
        Counter = new QLabel(centralwidget);
        Counter->setObjectName(QString::fromUtf8("Counter"));
        Counter->setGeometry(QRect(180, 22, 41, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font2.setPointSize(11);
        Counter->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        Remove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        CounterTip->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\350\231\232\346\213\237\346\230\276\347\244\272\345\231\250\346\225\260\351\207\217", nullptr));
        Counter->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINUI_H
