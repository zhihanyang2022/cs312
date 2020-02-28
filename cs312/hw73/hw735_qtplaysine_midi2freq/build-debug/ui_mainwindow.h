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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *verticalSlider_amp;
    QLabel *label_amp;
    QLabel *label_ampValue;
    QLabel *label_CMajor;
    QToolButton *toolButton_C4;
    QToolButton *toolButton_D4;
    QToolButton *toolButton_B4;
    QToolButton *toolButton_E4;
    QToolButton *toolButton_F4;
    QToolButton *toolButton_A4;
    QToolButton *toolButton_G4;
    QPushButton *pushButton_quit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        MainWindow->setMinimumSize(QSize(600, 400));
        MainWindow->setMaximumSize(QSize(600, 400));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalSlider_amp = new QSlider(centralwidget);
        verticalSlider_amp->setObjectName(QString::fromUtf8("verticalSlider_amp"));
        verticalSlider_amp->setGeometry(QRect(50, 80, 22, 202));
        verticalSlider_amp->setMaximum(100);
        verticalSlider_amp->setValue(50);
        verticalSlider_amp->setOrientation(Qt::Vertical);
        label_amp = new QLabel(centralwidget);
        label_amp->setObjectName(QString::fromUtf8("label_amp"));
        label_amp->setGeometry(QRect(30, 50, 71, 16));
        label_ampValue = new QLabel(centralwidget);
        label_ampValue->setObjectName(QString::fromUtf8("label_ampValue"));
        label_ampValue->setGeometry(QRect(30, 290, 71, 16));
        label_CMajor = new QLabel(centralwidget);
        label_CMajor->setObjectName(QString::fromUtf8("label_CMajor"));
        label_CMajor->setGeometry(QRect(140, 50, 111, 16));
        toolButton_C4 = new QToolButton(centralwidget);
        toolButton_C4->setObjectName(QString::fromUtf8("toolButton_C4"));
        toolButton_C4->setGeometry(QRect(140, 90, 41, 151));
        toolButton_D4 = new QToolButton(centralwidget);
        toolButton_D4->setObjectName(QString::fromUtf8("toolButton_D4"));
        toolButton_D4->setGeometry(QRect(200, 90, 41, 151));
        toolButton_B4 = new QToolButton(centralwidget);
        toolButton_B4->setObjectName(QString::fromUtf8("toolButton_B4"));
        toolButton_B4->setGeometry(QRect(500, 90, 41, 151));
        toolButton_E4 = new QToolButton(centralwidget);
        toolButton_E4->setObjectName(QString::fromUtf8("toolButton_E4"));
        toolButton_E4->setGeometry(QRect(260, 90, 41, 151));
        toolButton_F4 = new QToolButton(centralwidget);
        toolButton_F4->setObjectName(QString::fromUtf8("toolButton_F4"));
        toolButton_F4->setGeometry(QRect(320, 90, 41, 151));
        toolButton_A4 = new QToolButton(centralwidget);
        toolButton_A4->setObjectName(QString::fromUtf8("toolButton_A4"));
        toolButton_A4->setGeometry(QRect(440, 90, 41, 151));
        toolButton_G4 = new QToolButton(centralwidget);
        toolButton_G4->setObjectName(QString::fromUtf8("toolButton_G4"));
        toolButton_G4->setGeometry(QRect(380, 90, 41, 151));
        pushButton_quit = new QPushButton(centralwidget);
        pushButton_quit->setObjectName(QString::fromUtf8("pushButton_quit"));
        pushButton_quit->setGeometry(QRect(280, 270, 113, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_amp->setText(QApplication::translate("MainWindow", "Amplitude", nullptr));
        label_ampValue->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_CMajor->setText(QApplication::translate("MainWindow", "C Major Scale", nullptr));
        toolButton_C4->setText(QApplication::translate("MainWindow", "C", nullptr));
        toolButton_D4->setText(QApplication::translate("MainWindow", "D", nullptr));
        toolButton_B4->setText(QApplication::translate("MainWindow", "B", nullptr));
        toolButton_E4->setText(QApplication::translate("MainWindow", "E", nullptr));
        toolButton_F4->setText(QApplication::translate("MainWindow", "F", nullptr));
        toolButton_A4->setText(QApplication::translate("MainWindow", "A", nullptr));
        toolButton_G4->setText(QApplication::translate("MainWindow", "G", nullptr));
        pushButton_quit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
