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

// Store note and time together
struct NoteTm
{
  int note;
  int tm;
};

// clang-format off
const std::vector<NoteTm> one_meas_vec = {
                                          {7, 0},
                                          {0, 500},
                                          {9, 1000},
                                          {0, 1500},
                                          {10, 2000},
                                          {0, 2500},
                                          {9, 3000},
                                          {0, 3500}
                                          };
// Alternate choice or write your own
// const std::vector<NoteTm> one_meas_vec = {
//                                           {0, 0},
//                                           {4, 500},
//                                           {7, 1000},
//                                           {9, 1500},
//                                           {10, 2000},
//                                           {9, 2500},
//                                           {7, 3000},
//                                           {4, 3500}
//                                           };
// clang-format on

// additional constructor
CBluesBassTrack::CBluesBassTrack(uint32_t beginTm, uint32_t endTm,
                                 int scaleOffset, int chan, int patch, int vol,
                                 int pan, int startNote, int meas)
    : CInstrument(beginTm, endTm, scaleOffset, chan, patch, vol, pan, startNote,
                  meas) {}

void CBluesBassTrack::write_one_measure(int meas, int chan)
{
  CMidiPacket mp;

  // use get_note_offset(meas, get_start_note()) to get the pitch offset based on the chord used in meas
  // use get_measure_start_time(meas) to get the starting time for the measure we're writing

  uint16_t offset = get_note_offset(meas, get_start_note());  // offset from 0, the lowest possible data1 value
  uint32_t meas_tm = get_measure_start_time(meas);  // meas * 4000

  for (auto itr : one_meas_vec)
  {
    push_non(meas_tm + itr.tm, chan, itr.note + offset, 127);
    push_nof(meas_tm + 300 + itr.tm, chan, itr.note + offset);
  }

  set_meas_num(get_meas_num() + 1);
}
