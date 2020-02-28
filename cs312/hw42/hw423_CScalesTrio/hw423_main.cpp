/******************************************************
hw423_main.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw423
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-05
TIME: 16-35-55
******************************************************/

#ifndef HW423_CALTOTRACK_H_
#include "hw423_CAltoTrack.h"
#endif

#ifndef HW423_CBASSTRACK_H_
#include "hw423_CBassTrack.h"
#endif

#ifndef HW423_CSOPRANOTRACK_H_
#include "hw423_CSopranoTrack.h"
#endif

#ifndef HW421_CDELAYMS_H_
#include "hw421_CDelayMs.h"
#endif

#ifndef HW422_CAPPLEMIDISYNTH_H_ 
#include "hw422_CAppleMidiSynth.h"
#endif

#ifndef HW332CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

#include <iostream>
#include <vector>
#include <string>

using namespace CMP33;

void stuffPackets(CScalesTrack &cst)
{
  uint32_t tm = 0;

  cst.vtrk.push_back(CMidiPacket(tm, 0xC0 + cst.get_channel(), cst.get_patch()));
  cst.vtrk.push_back(CMidiPacket(tm, 0xB0 + cst.get_channel(), 7, cst.get_volume()));
  cst.vtrk.push_back(CMidiPacket(tm, 0xB0 + cst.get_channel(), 10, cst.get_pan()));

  int scale_counter = 0;
  int rhythm_counter = 0;
  do {
      int note = cst.vscale[scale_counter % cst.vscale.size()];
      int rhythm = cst.vrhythm[rhythm_counter % cst.vrhythm.size()];
      int velocity = 127;

      ++scale_counter;
      ++rhythm_counter;

      cst.vtrk.push_back(CMidiPacket(tm, 0x90 + cst.get_channel(), note + cst.get_noteOffset(), velocity));
      cst.vtrk.push_back(CMidiPacket(tm + rhythm - 1, 0x80 + cst.get_channel(), note + cst.get_noteOffset(), 0));

      tm += rhythm;
  } while (tm < cst.get_endTimestamp());
}

int main(int argc, char const * argv[])
{
  if (argc < 2) {
    std::cout << "hw423_CScalesTrio <tempo_per_sec>" << std::endl;
    return 1;
  }

  uint16_t endtime = 10000;

  uint16_t beginTime = 0;
  uint16_t startNote = 72;
  uint16_t chan = 0x01;
  uint16_t patch = 81;  // synth lead - sawtooth
  uint16_t vol = 90;
  uint16_t pan = 64;  // middle
  CSopranoTrack sop_trk(beginTime, endtime, startNote, chan, patch, vol, pan);

  beginTime = 0;
  startNote = 60;
  chan = 0x02;
  patch = 19;  // church organ
  vol = 100;
  pan = 0;  // left
  CAltoTrack alto_trk(beginTime, endtime, startNote, chan, patch, vol, pan);

  beginTime = 0;
  startNote = 36;
  chan = 0x03;
  patch = 32;  // acoustic bass
  vol = 127;
  pan = 127;
  CBassTrack bass_trk(beginTime, endtime, startNote, chan, patch, vol, pan);

  sop_trk.vscale = {6, 6, 6, 10, 15, 15, 15, 13, 10, 10, 10, 10, 5, 5, 5, 3};
  sop_trk.vrhythm = {250, 250, 250, 250};
  alto_trk.vscale = {6, 15, 10, 5};
  alto_trk.vrhythm = {1000, 1000, 1000, 1000};
  bass_trk.vscale = {6, 6, 6, 10, 15, 15, 15, 13, 10, 10, 10, 10, 5, 5, 5, 3};
  bass_trk.vrhythm = {250, 250, 250, 250};

  // Write the three tracks
  sop_trk.write_track();
  alto_trk.write_track(); 
  bass_trk.write_track();

  // create the playback vector vplay
  // // use std::copy for sop_trk, alto_trk, bass_trk with std::back_inserter(vplay)
  std::vector<CMidiPacket> vplay;

  stuffPackets(alto_trk);
  stuffPackets(sop_trk);
  stuffPackets(bass_trk);
  
  std::copy (alto_trk.vtrk.begin(), alto_trk.vtrk.end(), back_inserter(vplay));
  std::copy (sop_trk.vtrk.begin(), sop_trk.vtrk.end(), back_inserter(vplay));
  std::copy (bass_trk.vtrk.begin(), bass_trk.vtrk.end(), back_inserter(vplay));

  // vector vplay now holds all elements of sop, alto, bass vectors
  // sort vplay vector
  // it will use your operator< (less) routine
  std::sort(vplay.begin(), vplay.end());

  // Set the playback tempo
  // This is the variable you use
  // The number (120) is passed in from the command line
  CDelayMs::s_tempo = std::stoi(argv[1]);

  // create the CAppleMidiSynth object
  CAppleMidiSynth ams;
  for (auto itr : vplay)
  {
    std::cout << itr; // send CMidiPackets to cout while playing
    ams.send(itr);    // play the CMidiPacket
  }
}