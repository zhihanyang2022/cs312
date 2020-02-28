/******************************************************
hw431_CDrumMachine.h
Copyright (c) Carleton College CS312 free open source
Assignment: hw431
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-11
TIME: 16-07-11
******************************************************/

// hw431_CDrumMachine.h
#ifndef hw431_CDRUMMACHINE_H_
#define hw431_CDRUMMACHINE_H_

#ifndef hw431_CDRUMTRACK_H_
#include "hw431_CDrumTrack.h"
#endif

#include <cstdint>
#include <vector>

// DO NOT MODIFY

// You can add others
// Look up drum note numbers using the CS312 tool gmdrums
// Note: zero is not the correct number

// or conveniently from:
// https://en.wikipedia.org/wiki/General_MIDI#Percussion

const uint8_t kBASS_DRUM = 36;
const uint8_t kSNARE_DRUM = 38;  // acoustic snare
const uint8_t kCLAP = 39;
const uint8_t kCLOSED_HIHAT = 42;
const uint8_t kOPEN_HIHAT = 46;
const uint8_t kLOW_TOM = 45;
const uint8_t kHIGH_TOM = 50;
const uint8_t kSIDE_STICK = 37;
const uint8_t kWOOD_BLOCK = 76;  // high wood block

// DO NOT MODIFY class CDrumMachine
class CDrumMachine
{
public:
  // This vector holds all eight drum tracks (rows)
  std::vector<CDrumTrack> vDrumTracks;

  // the big 6 are all default constructed
  void make_track(const uint8_t note, const std::vector<std::string> &pats);
};

#endif // hw431_CDRUMMACHINE_H_