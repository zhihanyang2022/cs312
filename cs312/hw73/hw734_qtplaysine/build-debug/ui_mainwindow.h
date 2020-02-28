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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSlider *horizontalSlider_freq;
    QSlider *horizontalSlider_amp;
    QLabel *freq;
    QLabel *label_amp;
    QLabel *label_ampValue;
    QLabel *label_freqValue;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_play;
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
        horizontalSlider_freq = new QSlider(centralwidget);
        horizontalSlider_freq->setObjectName(QString::fromUtf8("horizontalSlider_freq"));
        horizontalSlider_freq->setGeometry(QRect(40, 80, 391, 22));
        horizontalSlider_freq->setMinimum(20);
        horizontalSlider_freq->setMaximum(4000);
        horizontalSlider_freq->setValue(220);
        horizontalSlider_freq->setOrientation(Qt::Horizontal);
        horizontalSlider_amp = new QSlider(centralwidget);
        horizontalSlider_amp->setObjectName(QString::fromUtf8("horizontalSlider_amp"));
        horizontalSlider_amp->setGeometry(QRect(40, 180, 391, 22));
        horizontalSlider_amp->setMinimum(0);
        horizontalSlider_amp->setMaximum(100);
        horizontalSlider_amp->setValue(50);
        horizontalSlider_amp->setOrientation(Qt::Horizontal);
        freq = new QLabel(centralwidget);
        freq->setObjectName(QString::fromUtf8("freq"));
        freq->setGeometry(QRect(40, 60, 111, 16));
        label_amp = new QLabel(centralwidget);
        label_amp->setObjectName(QString::fromUtf8("label_amp"));
        label_amp->setGeometry(QRect(40, 160, 91, 16));
        label_ampValue = new QLabel(centralwidget);
        label_ampValue->setObjectName(QString::fromUtf8("label_ampValue"));
        label_ampValue->setGeometry(QRect(450, 180, 59, 16));
        label_freqValue = new QLabel(centralwidget);
        label_freqValue->setObjectName(QString::fromUtf8("label_freqValue"));
        label_freqValue->setGeometry(QRect(450, 80, 59, 16));
        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(280, 280, 113, 32));
        pushButton_play = new QPushButton(centralwidget);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        pushButton_play->setGeometry(QRect(410, 280, 113, 32));
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
        freq->setText(QApplication::translate("MainWindow", "Frequency Hz", nullptr));
        label_amp->setText(QApplication::translate("MainWindow", "Amplitude", nullptr));
        label_ampValue->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_freqValue->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        pushButton_play->setText(QApplication::translate("MainWindow", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
