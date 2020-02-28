/******************************************************
hw423_CSopranoTrack.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw423
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-05
TIME: 16-36-30
******************************************************/

#ifndef HW423CSOPRANOTRACK_H_
#include "hw423_CSopranoTrack.h"
#endif

CSopranoTrack::CSopranoTrack(uint32_t beginTime, uint32_t endTime, uint8_t noteoffset, uint8_t channel,
                           uint8_t patch, uint8_t volume, uint8_t pan)
    : CScalesTrack(beginTime, endTime, noteoffset, channel,
                 patch, volume, pan)
{   
}

void CSopranoTrack::write_track() {
  
  vtrk.clear();
  
  uint32_t tm = 0;

  push_patch(0, get_channel(), get_patch());
  push_volume(0, get_channel(), get_volume());
  push_pan(0, get_channel(), get_pan());

  int scale_counter = 0;
  int rhythm_counter = 0;
  do {
      int note = vscale[scale_counter % vscale.size()];
      int rhythm = vrhythm[rhythm_counter % vrhythm.size()];
      int velocity = 127;

      ++scale_counter;
      ++rhythm_counter;

      push_non(tm, get_channel(), note + get_noteOffset(), velocity);
      push_nof(tm + rhythm - 1, get_channel(), note + get_noteOffset());

      tm += rhythm;
  } while (tm < get_endTimestamp());

}