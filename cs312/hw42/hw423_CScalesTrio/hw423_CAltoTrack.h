/******************************************************
hw423_CAltoTrack.h
Copyright (c) Carleton College CS312 free open source
Assignment: hw423
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-05
TIME: 16-38-07
******************************************************/

// hw423_CAltoTrack.h
#ifndef HW423_CALTOTRACK_H_
#define HW423_CALTOTRACK_H_

#ifndef HW423_CMIDITRACK_H_
#include "hw423_CMidiTrack.h"
#endif

#ifndef HW423_CSCALESTRACK_H_
#include "hw423_CScalesTrack.h"
#endif

class CAltoTrack : public CScalesTrack
{
public:
    CAltoTrack(uint32_t begintime, uint32_t endTime, uint8_t noteoffset, uint8_t channel,
               uint8_t patch, uint8_t volume, uint8_t pan);
    void write_track() override;
};
#endif // HW423_CALTOTRACK_H_