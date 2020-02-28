/******************************************************
hw511_CBluesPianoTrack.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw511
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-11
TIME: 16-10-34
******************************************************/

// hw511_CBluesPianoTrack.cpp
#ifndef HW511_CBLUESPIANOTRACK_H_
#include "hw511_CBluesPianoTrack.h"
#endif

struct NotesOneMeasure {
  int note1;
  int note2;
  int note3;
  int note4;
};

NotesOneMeasure meas1 = {66, 66, 66, 70};
NotesOneMeasure meas2 = {75, 75, 75, 73};
NotesOneMeasure meas3 = {70, 70, 70, 70};
NotesOneMeasure meas4 = {65, 65, 65, 63};
std::vector<int> time_deltas = {1000, 1000, 1000};

std::vector<NotesOneMeasure> notes = {meas1, meas2, meas3, meas4};

// additional constructor
CBluesPianoTrack::CBluesPianoTrack(uint32_t beginTm, uint32_t endTm,
                                   int scaleOffset, int chan, int patch,
                                   int vol, int pan, int startNote, int meas)
    : CInstrument(beginTm, endTm, scaleOffset, chan, patch, vol, pan, startNote,
                  meas) {}

void CBluesPianoTrack::write_one_measure(int meas, int chn)
{
  CMidiPacket mp;
  int kNOTE_DURATION = 300;
  uint32_t meas_tm = get_measure_start_time(meas);

  uint32_t current_tm = meas_tm;
  NotesOneMeasure current_notes = notes.at(meas % 4);
  
  push_non(current_tm, chn, current_notes.note1, 127);
  push_nof(current_tm + kNOTE_DURATION, chn, current_notes.note1);

  current_tm += time_deltas.at(0);
  push_non(current_tm, chn, current_notes.note2, 127);
  push_nof(current_tm + kNOTE_DURATION, chn, current_notes.note2);

  current_tm += time_deltas.at(1);
  push_non(current_tm, chn, current_notes.note3, 127);
  push_nof(current_tm + kNOTE_DURATION, chn, current_notes.note3);

  current_tm += time_deltas.at(2);
  push_non(current_tm, chn, current_notes.note4, 127);
  push_nof(current_tm + kNOTE_DURATION, chn, current_notes.note4);

  set_meas_num(get_meas_num() + 1);
}