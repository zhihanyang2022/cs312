/******************************************************
hw423_CScalesTrack.h
Copyright (c) Carleton College CS312 free open source
Assignment: hw423
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-05
TIME: 16-37-05
******************************************************/

// hw423_CScalesTrack.h
#ifndef HW423_CSCALESTRACK_H_
#define HW423_CSCALESTRACK_H_

#ifndef HW423_CMIDITRACK_H_
#include "hw423_CMidiTrack.h"
#endif

// DO NOT MODIFY THIS CODE

class CScalesTrack : public CMidiTrack
{
public:
  std::vector<int> vscale;
  std::vector<int> vrhythm;

  CScalesTrack(uint32_t beginTime, uint32_t endTime, uint8_t noteoffset, uint8_t channel,
               uint8_t patch, uint8_t volume, uint8_t pan);

  int get_note(); // choose a random scale note
  void write_scales_track();
  virtual void write_track(); // must define it was declared pure virtual in CMidiTrack
};

// SCALE NOTES
// See class web page for more information
// You can add your own to the list.
// clang-format off
const std::vector<int> vmajor_pentatonic{0, 2, 4, 7, 9, 12};        // Major pentatonic
const std::vector<int> vminor_pentatonic{0, 3, 5, 7, 10, 12};       // Minor pentatonic
const std::vector<int> vragtime{0, 2, 3, 4, 7, 9, 12};              // Ragtime scale
const std::vector<int> vrock_blues{0, 3, 4, 7, 9, 10, 12};          // Rock blues Scales
const std::vector<int> vminor_blues{0, 3, 5, 6, 7, 10, 12};         // Minor blues Scales
const std::vector<int> v6note_blues{0, 3, 5, 6, 7, 10, 12};         // 6 note blues Scales
const std::vector<int> v7note_blues{0, 2, 3, 5, 6, 9, 10, 12};      // 7 note blues Scales
const std::vector<int> vmideast{0, 1, 4, 5, 6, 8, 11, 12};          // Middle Eastern scale
const std::vector<int> vjapanese{0, 1, 5, 7, 8, 12};                // Japanese scale
const std::vector<int> voctotonic{0, 1, 3, 4, 6, 7, 9, 10, 12};     // Octotonic jazz scale half step, whole step
const std::vector<int> vwholetone{0, 2, 4, 6, 8, 10, 12};           // Whole tone, whole step, whole step
const std::vector<int> vflamenco{0, 1, 4, 5, 7, 8, 11, 12};          // Flamenco
const std::vector<int> vphrygian_dominant{0, 1, 4, 5, 7, 8, 10, 12}; // Phrygian dominant
// clang-format ON

////// JE ADDED for hw423
/* DURATION VALUES
duration values are expressed in milliseconds with a
quarter note = 1000 at a tempo of 60 beats per minute.
*/
const std::vector<int> vrhythm0 = {500, 250, 250, 500}; // the original hw423_CScalesTrack pattern
// je additional patterns
const std::vector<int> vrhythm1 = {250, 250, 500};
const std::vector<int> vrhythm2 = {500, 500};
const std::vector<int> vrhythm3 = {250, 500, 1000};
const std::vector<int> vrhythm4 = {125, 250, 500, 1000};
const std::vector<int> vrhythm5 = {333, 667, 1000};
const std::vector<int> vrhythm6 = {333, 333, 334, 667};
const std::vector<int> vrhythm7 = {333, 333, 333, 333, 667, 667, 1000};

#endif // HW423_CSCALESTRACK_H_