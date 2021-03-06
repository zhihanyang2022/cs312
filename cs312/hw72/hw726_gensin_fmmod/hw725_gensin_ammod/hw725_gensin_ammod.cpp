/******************************************************
hw722_gensin_phasor.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw722
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

// Fc carrierFrequncy, Ac carrierAmplitude,
// Fm modulationFrequency, Am modulationAmplitude,
// M modulation Index, secs duration in seconds
std::vector<MY_TYPE> am_modulation(MY_TYPE Fc, MY_TYPE Ac,
                                   MY_TYPE Fm, MY_TYPE Am,
                                   MY_TYPE M, MY_TYPE secs)
{
  std::vector<MY_TYPE> v;
  const MY_TYPE kAM = k2PIT * Fm;
  const MY_TYPE kFC = k2PIT * Fc;

  for (int n = 0; n < secs * FS; n++) {
    MY_TYPE samp = (1 + M * sin(kAM * n)) * Ac * sin(kFC * n);
    v.push_back(samp);
  }
  /*----------------------------------------------------
   implement the FM formula on the class web page
   kAM = 2*pi*T*Fm is a constant that can be pre-calculated outside of the loop
   kFC = 2*pi*T*Fc is a constant that can be pre-calculated outside of the loop

  loop for samples 0 to total number of samples
       samp = (1 + M * sin(kAM * n)) * Ac * sin(kFC * n);
       vout.push_back(samp);
  end loop
  ----------------------------------------------------*/
  return v;
}

int main(int argc, char *argv[])
{
  std::vector<MY_TYPE> vout;
  // params are
  // carrierFreq, carrierAmplitude, modulatorFreq, modulatorAmplitude, modulation Index, duration
  vout = am_modulation(700, 0.5, 400, 0.5, .57, 2.5);
  samples2wavfile("variation_1.wav", vout);

  vout.clear();
  vout = am_modulation(400, 0.5, 3.0, 0.8, -1.0, 2.5);
  samples2wavfile("variation_2.wav", vout);

  vout.clear();
  vout = am_modulation(400, 0.5, 25.0, 0.8, 1.25, 2.5);
  samples2wavfile("variation_3.wav", vout);

  return 0;
}