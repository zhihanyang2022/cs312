/******************************************************
hw431_main.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw431
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-10
TIME: 10-37-58
******************************************************/

// hw431_main.cpp
#ifndef hw431_CDRUMACHINE_H_
#include "hw431_CDrumMachine.h"
#endif

#ifndef hw423_CMIDITRACK_H
#include "hw423_CMidiTrack.h"
#endif

#ifndef HW421_CDELAYMS_H_
#include "hw421_CDelayMs.h"
#endif

#ifndef HW422_CAPPLEMIDISYNTH_H_
#include "hw422_CAppleMidiSynth.h"
#endif

#include <iostream>

using namespace CMP33;

int main()
{
  // declare the playback vector
  std::vector<CMidiPacket> vplay;

  // create the drum machine
  CDrumMachine dm;

  // similar to a sequencer interface
  // stuff each row into the dm.tracks vector
  dm.make_track(kBASS_DRUM, {"1000", "1000", "1000", "1000"});
  dm.make_track(kSNARE_DRUM, {"0001", "0010", "0001", "0010"});
  dm.make_track(kCLAP, {"0000", "0000", "0000", "0010"});
  dm.make_track(kCLOSED_HIHAT, {"1000", "1000", "1000", "1000"});
  dm.make_track(kOPEN_HIHAT, {"0010", "0010", "0010", "0011"});
  dm.make_track(kLOW_TOM, {"0010", "0000", "0000", "0000"});
  dm.make_track(kHIGH_TOM, {"0001", "0001", "0010", "0010"});
  dm.make_track(kSIDE_STICK, {"0010", "0100", "0100", "0101"});

  // insert mps from each track to one vector called vplay
  for (auto n = 0; n < dm.vDrumTracks.size(); ++n)
  {
    dm.vDrumTracks[n].write_track(4);
    std::copy(dm.vDrumTracks[n].vtrk.begin(), dm.vDrumTracks[n].vtrk.end(), std::back_inserter(vplay));
  }
//   vplay.shrink_to_fit();

  std::sort(vplay.begin(), vplay.end());

  // write vplay to std::cout
  for (auto mp : vplay) {
      std::cout << mp;
  }

  // set the CDelayMs::s_tempo, try 75
  CDelayMs::s_tempo = 75;
  CAppleMidiSynth ams;
  ams.send(vplay);
};
