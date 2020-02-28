/******************************************************
hw621_cmidiin_cmp33.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw621
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-18
TIME: 17-52-59
******************************************************/

//*****************************************//
//  cmidiin.cpp
//  by Gary Scavone, 2003-2004.
//
//  Simple program to test MIDI input and
//  use of a user callback function.
//
//*****************************************//

#include <iostream>
#include <cstdlib>
#include "RtMidi.h"

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

using namespace CMP33;

void usage( void ) {
  // Error function in case of incorrect command-line
  // argument specifications.
  std::cout << "\nuseage: cmidiin <port>\n";
  std::cout << "    where port = the device to use (first / default = 0).\n\n";
  exit( 0 );
}

// added by Zhihan

double deltatime_sum_sec = 0;  // a running sum of deltatimes in seconds

// convert deltatimes from seconds to milliseconds
double sec2milli( double sec ) {
  return sec * 1000;
}

void mycallback( double deltatime, std::vector< unsigned char > *message, void */*userData*/ )
{
  // previous format: Byte 0 = 144 (status), Byte 1 = 84 (data1), Byte 2 = 100 (data2), stamp = 0 (timestamp)
  
  CMP33::CMidiPacket mp;  // use default constructor
  
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
  std::cout << mp; 
}

// This function should be embedded in a try/catch block in case of
// an exception.  It offers the user a choice of MIDI ports to open.
// It returns false if there are no ports available.
bool chooseMidiPort( RtMidiIn *rtmidi );

int main( int argc, char ** /*argv[]*/ )
{
  RtMidiIn *midiin = 0;

  // Minimal command-line check.
  if ( argc > 2 ) usage();

  try {

    // RtMidiIn constructor
    midiin = new RtMidiIn();

    // Call function to select port.
    if ( chooseMidiPort( midiin ) == false ) goto cleanup;

    // Set our callback function.  This should be done immediately after
    // opening the port to avoid having incoming messages written to the
    // queue instead of sent to the callback function.
    midiin->setCallback( &mycallback );

    // Don't ignore sysex, timing, or active sensing messages.
    midiin->ignoreTypes( false, false, false );

    std::cout << "\nReading MIDI input ... press <enter> to quit.\n";
    char input;
    std::cin.get(input);

  } catch ( RtMidiError &error ) {
    error.printMessage();
  }

 cleanup:

  delete midiin;

  return 0;
}

bool chooseMidiPort( RtMidiIn *rtmidi )
{
  std::cout << "\nWould you like to open a virtual input port? [y/N] ";

  std::string keyHit;
  std::getline( std::cin, keyHit );
  if ( keyHit == "y" ) {
    rtmidi->openVirtualPort();
    return true;
  }

  std::string portName;
  unsigned int i = 0, nPorts = rtmidi->getPortCount();
  if ( nPorts == 0 ) {
    std::cout << "No input ports available!" << std::endl;
    return false;
  }

  if ( nPorts == 1 ) {
    std::cout << "\nOpening " << rtmidi->getPortName() << std::endl;
  }
  else {
    for ( i=0; i<nPorts; i++ ) {
      portName = rtmidi->getPortName(i);
      std::cout << "  Input port #" << i << ": " << portName << '\n';
    }

    do {
      std::cout << "\nChoose a port number: ";
      std::cin >> i;
    } while ( i >= nPorts );
    std::getline( std::cin, keyHit );  // used to clear out stdin
  }

  rtmidi->openPort( i );

  return true;
}
