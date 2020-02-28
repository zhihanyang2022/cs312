#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <iostream>

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

#ifndef HW421_CDELAYMS_H_
#include "hw421_CDelayMs.h"
#endif

using namespace CMP33;

// hw711 variables
QPlainTextEdit* pte = nullptr;
// hw713 variables
bool isRecording = false;
bool isFirstTimestampCaptured = false;
uint32_t firstRecordTimestamp = 0;
std::vector<CMidiPacket> vplay;

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

    CMidiPacket mp;
    static uint32_t tm = 0;
    uint8_t st;
    uint8_t d1;
    uint8_t d2;
    unsigned int nBytes = message->size();

    if ( nBytes == 2 )
    {
            st = message->at( 0 );
            d1 = message->at( 1 );
            tm += ( deltatime * 1000 );
            mp = {tm, st, d1};
        }
        else if ( nBytes == 3 )
        {
            st = message->at( 0 );
            d1 = message->at( 1 );
            d2 = message->at( 2 );
            tm += ( deltatime * 1000 );
            mp = {tm, st, d1, d2};
        }

    // output
    QString str = QString::fromStdString(mp.to_string() + "\n");
    // the incorrect way to do this:
    // QString str;
    // str = QString::fromStdString(mp.to_string() + "\n");
    // to test this:
    // std::cout << mp.string() << std::endl;
    pte->insertPlainText(str);

    vplay.push_back(mp);
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

void MainWindow::on_pushButton_record_clicked()
{
    // highlighting
    allButtonsOff();
    ui->pushButton_record->setChecked( true );
    isRecording = true;
    isFirstTimestampCaptured = false;
    vplay.clear();
}

void MainWindow::on_pushButton_stop_clicked()
{
    // highlighting
    allButtonsOff();
    ui->pushButton_stop->setChecked( true );
    isRecording = false;
    isFirstTimestampCaptured = true;
}


void MainWindow::on_pushButton_clear_clicked()
{
    // highlighting
    allButtonsOff();
    ui->pushButton_clear->setChecked( true );
    pte->clear();
    isRecording = false;
    isFirstTimestampCaptured = true;
    vplay.clear();
}

void MainWindow::on_pushButton_play_clicked()
{
    // highlighting
    allButtonsOff();
    ui->pushButton_play->setChecked( true );
    isRecording = false;
    isFirstTimestampCaptured = true;

    for (auto mp : vplay) {
        static uint32_t prevTm = 0;
        uint32_t nowTm = mp.get_timestamp();
        uint32_t delay = nowTm - prevTm;
        std::vector<unsigned char> message;

        message.push_back(mp.get_status());
        message.push_back(mp.get_data1());
        if (mp.get_length() == 3) {
          message.push_back(mp.get_data2());
        }

        CDelayMs(delay, false);
        gmidiout->sendMessage( &message );
    }
}

void MainWindow::allButtonsOff()
{
    ui->pushButton_record->setChecked( false );
    ui->pushButton_stop->setChecked( false );
    ui->pushButton_play->setChecked( false );
    ui->pushButton_clear->setChecked( false );
}
