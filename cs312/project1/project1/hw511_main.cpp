/******************************************************
hw511_main.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw511
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-11
TIME: 16-11-09
******************************************************/

// hw511_main.cpp
#ifndef HW511_CINSTRUMENT_H_
#include "hw511_CInstrument.h"
#endif

#ifndef HW511_CBLUEMELODYTRACk_H
#include "hw511_CBluesMelodyTrack.h"
#endif

#ifndef HW511_CBLUESPIANOTRACK_H
#include "hw511_CBluesPianoTrack.h"
#endif

#ifndef HW511_CBLUESBASSTRACK_H
#include "hw511_CBluesBassTrack.h"
#endif

#ifndef hw431_CDRUMMACHINE_H_
#include "hw431_CDrumMachine.h"
#endif

#ifndef HW421_CDELAYMS_H_
#include "hw421_CDelayMs.h"
#endif

#ifndef HW422_CAPPLEMIDISYNTH_H_
#include "hw422_CAppleMidiSynth.h"
#endif

#include <vector>

using namespace CMP33;

std::vector<CMidiPacket> vplay;

void write_melody()
{
  // S A X
  uint32_t startTm = 0;
  int scaleOffset = 0;
  int chan = 0;
  int patch = 81;  // church organ 20
  // Trumpet: 56
  // Other atches I tried
  // Tenor Sax
  // Electric Guitar (jazz)
  // Drawbar organ
  // Lead 2 (sawtooth)
  // Clarinet

  int vol = 127;
  int pan = 32; // pan left -32 from center 64
  int startNote = 60;  // 60
  int meas = 0;

  // create the synth lead track
  CBluesMelodyTrack synth_trk(startTm, kSONG_END_TIME, scaleOffset, chan, patch, vol,
                            pan, startNote, meas);
  synth_trk.write_track();
  // append to vplay
  std::copy(synth_trk.vtrk.begin(), synth_trk.vtrk.end(),
          std::back_inserter(vplay));
}

void write_piano()
{
  // P I A N O
  uint32_t startTm = 0;
  int scaleOffset = 0;
  int chan = 1;
  int patch = 0; // piano
  int vol = 127;
  int pan = 64; // pan center
  int startNote = 48;
  int meas = 0;

  CBluesPianoTrack pno_trk(startTm, kSONG_END_TIME, scaleOffset, chan, patch,
                           vol, pan, startNote, meas);
  pno_trk.write_track();
  // append to vplay
  std::copy(pno_trk.vtrk.begin(), pno_trk.vtrk.end(),
            std::back_inserter(vplay));
}

void write_bass()
{
  // B A S S
  uint32_t startTm = 0;
  int scaleOffset = 0;
  int chan = 2;
  int patch = 32; // acoustic bass
  int vol = 127;
  int pan = 92; // pan right +32 from center 64
  int startNote = 36;
  int meas = 0;

  CBluesBassTrack bass_trk(startTm, kSONG_END_TIME, scaleOffset, chan, patch,
                           vol, pan, startNote, meas);
  bass_trk.write_track();
  // append to vplay
  std::copy(bass_trk.vtrk.begin(), bass_trk.vtrk.end(),
            std::back_inserter(vplay));
}

void write_drums()
{
  CDrumMachine dm;
  dm.make_track(kCLAP, {"0000", "0000", "0000", "0101"});

  int loops = kSONG_END_TIME / 4000;
  for (auto n = 0; n < dm.vDrumTracks.size(); ++n)
  {
    dm.vDrumTracks[n].write_track(loops);
    // append each drum track to vplay
    std::copy(dm.vDrumTracks[n].vtrk.begin(),
              dm.vDrumTracks[n].vtrk.end(), std::back_inserter(vplay));
  }
}

int main(int argc, char *argv[])
{
  if (argc == 1) {
    std::cout << "project1 <output? (y or n)>" << std::endl;
    return 1;
  }

  // write tracks
  write_melody();
  write_piano();
  write_bass();
  write_drums();

  // sort the playback vector using CMidiPacket43::operator<
  std::sort(vplay.begin(), vplay.end());

  // output for MIDIDisplay
  
  if (*argv[1] == 'y') {
    for (auto itr : vplay)
    std::cout << itr;
  }

  CDelayMs::s_tempo = 120;
  CAppleMidiSynth ams;
  ams.send(vplay);
}
