#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <iostream>

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

using namespace CMP33;

QPlainTextEdit* pte = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pte = ui->plainTextEdit;
    init_midi_in( 1 );
    init_midi_out( 1 );
}

MainWindow::~MainWindow()
{
    delete ui;
}

double sec2milli( double sec ) {
  return sec * 1000;
}

void mycallback( double deltatime, std::vector<unsigned char>* message, void* /*userData*/ )
{
    // previous format: Byte 0 = 144 (status), Byte 1 = 84 (data1), Byte 2 = 100 (data2), stamp = 0 (timestamp)

    CMP33::CMidiPacket mp;  // use default constructor

    static double deltatime_sum_sec = 0;
    deltatime_sum_sec += sec2milli(deltatime);  // add to running sum

      // set attributes of mp
    mp.set_timestamp(deltatime_sum_sec);
    mp.set_status((int)message->at(0));
    mp.set_data1((int)message->at(1));

    unsigned int nBytes = message->size();
    if (nBytes > 2) {  // if data2 exists
      mp.set_data2((int)message->at(2));
    }

    // output
    QString str = QString::fromStdString(mp.to_string() + "\n");
    // the incorrect way to do this:
    // QString str;
    // str = QString::fromStdString(mp.to_string() + "\n");
    // to test this:
    // std::cout << mp.string() << std::endl;
    pte->insertPlainText(str);
}

void MainWindow::init_midi_in( uint32_t num )
{
  try {

    gmidiin = new RtMidiIn();
//    gmidiin->openVirtualPort();
    gmidiin->openPort(num);
    gmidiin->setCallback( &mycallback );
    gmidiin->ignoreTypes( false, false, false );
    std::cout << gmidiin->getPortName() << std::endl;

  } catch ( RtMidiError &error ) {
    error.printMessage();
  }

}

void MainWindow::init_midi_out( uint32_t num )
{
    try
    {
      gmidiout = new RtMidiOut();
//      gmidiout->openVirtualPort();
      gmidiout->openPort(num);
    }

    catch ( RtMidiError& error )
    {
        error.printMessage();
        exit( EXIT_FAILURE );
    }
}
