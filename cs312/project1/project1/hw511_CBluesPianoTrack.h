/******************************************************
hw511_CBluesPianoTrack.h
Copyright (c) Carleton College CS312 free open source
Assignment: hw511
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-11
TIME: 16-10-43
******************************************************/

// hw511_CBluesPianoTrack.h
#ifndef HW511_CBLUESPIANOTRACK_H_
#define HW511_CBLUESPIANOTRACK_H_

#ifndef HW511_CINSTRUMENT_H_
#include "hw511_CInstrument.h"
#endif

// DO NOT MODIFY

class CBluesPianoTrack : public CInstrument
{
public:
  // constructor
  CBluesPianoTrack(uint32_t beginTm, uint32_t endTm, int scaleOffset, int chan,
                   int patch, int vol, int pan, int startNote, int meas);

  // This is the only function needed
  // write_track() is inherited from CInstrument
  void write_one_measure(int meas, int chan) override;
};
#endif // HW511_CBLUESPIANOTRACK_H_