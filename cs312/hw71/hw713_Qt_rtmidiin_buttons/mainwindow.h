#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>

#ifndef RTMIDI_H
#include "RtMidi.h"
#endif

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_record_clicked();

    void on_pushButton_stop_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_play_clicked();

private:
    Ui::MainWindow *ui;

    RtMidiIn* gmidiin;
    RtMidiOut* gmidiout;

    void init_midi_in( uint32_t num );
    void init_midi_out( uint32_t num );

    // button highlighting
    void allButtonsOff();
};

// hw711 variables
extern QPlainTextEdit* pte;
// hw713 variables
extern bool isRecording;
extern bool isFirstTimestampCaptured;
extern uint32_t firstRecordTimestamp;
extern std::vector<CMP33::CMidiPacket> vplay;

#endif // MAINWINDOW_H
