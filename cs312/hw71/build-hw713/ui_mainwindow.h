/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton_record;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_play;
    QPushButton *pushButton_stop;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 480);
        MainWindow->setMinimumSize(QSize(640, 480));
        MainWindow->setMaximumSize(QSize(640, 480));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 90, 601, 321));
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        pushButton_record = new QPushButton(centralwidget);
        pushButton_record->setObjectName(QString::fromUtf8("pushButton_record"));
        pushButton_record->setGeometry(QRect(20, 40, 113, 32));
        pushButton_record->setCheckable(true);
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(510, 40, 113, 32));
        pushButton_clear->setCheckable(true);
        pushButton_play = new QPushButton(centralwidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setGeometry(QRect(180, 40, 113, 32));
        pushButton_play->setCheckable(true);
        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(350, 40, 113, 32));
        pushButton_stop->setCheckable(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MIDI Monitor", nullptr));
        pushButton_record->setText(QApplication::translate("MainWindow", "Record", nullptr));
        pushButton_clear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        pushButton_play->setText(QApplication::translate("MainWindow", "Play", nullptr));
        pushButton_stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
