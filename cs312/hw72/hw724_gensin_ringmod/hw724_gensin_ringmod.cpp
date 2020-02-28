/******************************************************
hw724_gensin_ringmod.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw724
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-24
TIME: 19-31-30
******************************************************/

#include "sndfile.hh"
#include <iostream>
#include <vector>
#include <cmath> // for M_PI

// either_or
typedef float MY_TYPE;
#define LIB_SF_FORMAT SF_FORMAT_FLOAT; // SF_FORMAT_MY_TYPE defiend in  "sndfile.h"
// typedef double MY_TYPE;
// #define LIB_SF_FORMAT SF_FORMAT_DOUBLE; // SF_FORMAT_MY_TYPE defiend in  "sndfile.h"
// END either_or

const int FS = 44100;       // CD sample rate
const MY_TYPE T = 1.0 / FS; // sample period
const MY_TYPE k2PI = M_PI * 2.0;
const MY_TYPE k2PIT = k2PI * T;

std::vector<MY_TYPE> gen_sin_phasor(MY_TYPE freq, MY_TYPE ampl, MY_TYPE secs)
{
  std::vector<MY_TYPE> v;
  MY_TYPE phzNow;
  MY_TYPE phzIncr;
  phzNow = 0;
  phzIncr = k2PI * freq / FS;
  for (int i = 0; i < secs * FS; i++) {
    v.push_back(ampl*sin(phzNow));
    phzNow += phzIncr;
    if (phzNow > k2PI) {
      phzNow = phzNow - k2PI;
    }
  }
  /*----------------------------------------------------
  declare variable MY_TYPE phzNow
  declare variable MY_TYPE phzIncr
  set phzNow to zero
  calculate the phase increment in radians for freq
  BEGIN_LOOP from 0 to number of samples in secs paramater
  push ampl*sin(phzNow) to vector v
  increment phzNow
  check if phzNow greater than 2pi
  if so wrap around (phzNow = phzNow - 2pi)
  END_LOOP
  ----------------------------------------------------*/
  return v;
}

bool samples2wavfile(const char *fname, const std::vector<MY_TYPE> &v)
{
  // code borrowed and modified from libsndfile example sndfilehandle.cc
  // mostly from create_file(...) and format from main()
  SndfileHandle file;
  const int channels = 1;
  const int srate = FS;
  const int format = SF_FORMAT_WAV | LIB_SF_FORMAT;

  file = SndfileHandle(fname, SFM_WRITE, format, channels, srate);

  // using vector instead of buffer array
  // C++ vector elements are stored in contiguous memory, same as array
  // &v[0] is pointer to first element of vector
  file.write(&v[0], v.size());
  return true;
}

int main(int argc, char *argv[])
{
  /*----------------------------------------------
  modulating sine wave at 400 Hz, ampl 1.0, duration 1.5 seconds
  carrier sine wave at 700 Hz, ampl 1.0, duration 1.5 seconds
  output wave file name: "hw724_gensin_ringmod.wav"
  ----------------------------------------------*/

  std::vector<MY_TYPE> modulator = gen_sin_phasor(400.0, 1.0, 1.5);
  std::vector<MY_TYPE> carrier = gen_sin_phasor(700.0, 1.0, 1.5);

  std::vector<MY_TYPE> ringmod;
  for (int i = 0; i < modulator.size(); i++) {
    ringmod.push_back(modulator.at(i) * carrier.at(i));
  }
  samples2wavfile("hw724_gensin_ringmod.wav", ringmod);
  return 0;
}
