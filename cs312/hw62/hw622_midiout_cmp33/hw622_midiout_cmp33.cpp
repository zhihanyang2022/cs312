/******************************************************
hw622_midiout_cmp33.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw62
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-19
TIME: 09-42-10
******************************************************/

//*****************************************//
//  midiout.cpp
//  by Gary Scavone, 2003-2004.
//
//  Simple program to test MIDI output.
//
//  modified for CS312
//*****************************************//

#include <iostream>
#include <cstdlib>

#ifndef RTMIDI_H
#include "RtMidi.h"
#endif

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

#ifndef HW421_CDELAYMS_H_
#include "hw421_CDelayMs.h"
#endif

using namespace CMP33;

RtMidiOut *midiout = 0;
std::vector<CMidiPacket> vplay;

bool chooseMidiPort(RtMidiOut *rtmidi)
{
  std::cout << "\nWould you like to open a virtual output port? [y/N] ";

  std::string keyHit;
  std::getline( std::cin, keyHit );
  if ( keyHit == "y" ) {
    rtmidi->openVirtualPort();
    return true;
  }

  std::string portName;
  unsigned int i = 0, nPorts = rtmidi->getPortCount();
  if ( nPorts == 0 ) {
    std::cout << "No output ports available!" << std::endl;
    return false;
  }

  if ( nPorts == 1 ) {
    std::cout << "\nOpening " << rtmidi->getPortName() << std::endl;
  }
  else {
    for ( i=0; i<nPorts; i++ ) {
      portName = rtmidi->getPortName(i);
      std::cout << "  Output port #" << i << ": " << portName << '\n';
    }

    do {
      std::cout << "\nChoose a port number: ";
      std::cin >> i;
    } while ( i >= nPorts );
  }

  std::cout << "\n";
  rtmidi->openPort( i );

  return true;
}

void sendCMidiPacket(const CMidiPacket &mp)
{
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
  midiout->sendMessage( &message );
}

void stuffPackets()
{
  CMidiPacket mp;
  mp = CMidiPacket{0, 0xC0, 0};
  vplay.push_back(mp);

  mp = CMidiPacket(1000, 0x90, 60, 127);
  vplay.push_back(mp);
  mp = CMidiPacket(1900, 0x90, 60, 0);
  vplay.push_back(mp);

  mp = CMidiPacket(2000, 0x90, 61, 127);
  vplay.push_back(mp);
  mp = CMidiPacket(2900, 0x90, 61, 0);
  vplay.push_back(mp);

  mp = CMidiPacket(3000, 0x90, 62, 127);
  vplay.push_back(mp);
  mp = CMidiPacket(3900, 0x90, 62, 0);
  vplay.push_back(mp);
}

bool openMidiOutPort()
{
  try {
    midiout = new RtMidiOut();
  }
  catch ( RtMidiError &error ) {
    error.printMessage();
    return false;
    exit( EXIT_FAILURE );
  }

  // Call function to select port.
  try {
    bool ok = chooseMidiPort(midiout);
    if (ok == false)
      return false;
  }
  catch ( RtMidiError &error ) {
    error.printMessage();
    return false;
  }

  return true;
}

void closeMidiOutPort()
{
  delete midiout;
}

/*========================
   Do not change main()
========================*/
int main()
{
  // OPEN RtMidiOut port
  if (!openMidiOutPort())
    return 0;

  // create vplay vector
  stuffPackets();
  // set tempo
  CDelayMs::s_tempo = 180;
  // play
  for (auto itr : vplay)
    sendCMidiPacket(itr);

  // CLOSE RtMidiOut port
  closeMidiOutPort();

  return 0;
}
