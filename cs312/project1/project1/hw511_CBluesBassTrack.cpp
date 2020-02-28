/******************************************************
hw511_CBluesBassTrack.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw511
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-11
TIME: 16-09-22
******************************************************/

// hw511_CBluesBassTrack.cpp
#ifndef HW511_CBLUESBASSTRACK_H_
#include "hw511_CBluesBassTrack.h"
#endif

#ifndef HW411_RAND_INT_H_
#include "hw411_rand_int.h"
#endif

const std::vector<int> notes = {66 - 12, 75 - 12, 70 - 12, 65 - 12};  // one long note per measure

// additional constructor
CBluesBassTrack::CBluesBassTrack(uint32_t beginTm, uint32_t endTm,
                                 int scaleOffset, int chan, int patch, int vol,
                                 int pan, int startNote, int meas)
    : CInstrument(beginTm, endTm, scaleOffset, chan, patch, vol, pan, startNote,
                  meas) {}

void CBluesBassTrack::write_one_measure(int meas, int chan)
{
  int kNOTE_DURATION = 3999;
  uint32_t meas_tm = get_measure_start_time(meas);
  int note = notes.at(meas % 4);

  push_non(meas_tm, chan, note, 80);
  push_nof(meas_tm + kNOTE_DURATION, chan, note);

  set_meas_num(get_meas_num() + 1);
}
