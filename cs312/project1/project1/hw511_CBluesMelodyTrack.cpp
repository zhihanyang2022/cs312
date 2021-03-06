/******************************************************
hw511_CBluesMelodyTrack.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw511
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-11
TIME: 16-09-56
******************************************************/

// hw511_CBluesMelodyTrack
#ifndef HW511_CBLUESMELODYTRACK_H_
#include "hw511_CBluesMelodyTrack.h"
#endif

#ifndef HW411_RAND_INT_H_
#include "hw411_rand_int.h"
#endif

#ifndef VOLUMECONTROLLER_H_
#include "CVolumeController.h"
#endif

#include <cstdint>
#include <vector>

const std::vector<int> notes = {66, 75, 70, 65};  // one long note per measure

// additional constructor
CBluesMelodyTrack::CBluesMelodyTrack(uint32_t beginTm, uint32_t endTm,
                                     int scaleOffset, int chan, int patch, int vol,
                                     int pan, int startNote, int meas)
    : CInstrument(beginTm, endTm, scaleOffset, chan, patch, vol, pan, startNote,
                  meas) {}

void CBluesMelodyTrack::write_one_measure(int meas, int chan)
{
    int kNOTE_DURATION = 3999;  // note spans the entire measure
    uint32_t meas_tm = get_measure_start_time(meas);
    int note = notes.at(meas % 4);

    CVolumeController vc;
    push_non(meas_tm, chan, note, 80);
//    vc.linearly_interpolate(this, meas_tm, meas_tm + kNOTE_DURATION, 80, 0);  // linear decay
     vc.wiggly_interpolate(this, meas_tm, meas_tm + kNOTE_DURATION, 80, 0, 16, 40);  // sin oscillation
//    push_volume * n
    push_nof(meas_tm + kNOTE_DURATION, chan, note);

    set_meas_num(get_meas_num() + 1);
}
