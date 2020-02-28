/******************************************************
hw422_CAppleMidiSynth.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw422
Zhihan Yang yangz2@carleton.edu
DATE: 2020-02-04
TIME: 21-37-51
******************************************************/

// hw422_CAppleMidiSynth.cpp
#ifndef HW422_CAPPLE_MIDISYNTH_H_
#include "hw422_CAppleMidiSynth.h"
#endif

#ifndef HW421_CDELAYMS_H_
#include "hw421_CDelayMs.h"
#endif

// #include <AssertMacros.h>

CAppleMidiSynth::CAppleMidiSynth()
{
  	OSStatus result;
	//create the nodes of the graph
	AUNode synthNode, limiterNode, outNode;
	
	AudioComponentDescription cd;
	cd.componentManufacturer = kAudioUnitManufacturer_Apple;
	cd.componentFlags = 0;
	cd.componentFlagsMask = 0;

	__Require_noErr (result = NewAUGraph (&outGraph), home);

	cd.componentType = kAudioUnitType_MusicDevice;
	cd.componentSubType = kAudioUnitSubType_DLSSynth;

	__Require_noErr (result = AUGraphAddNode (outGraph, &cd, &synthNode), home);

	cd.componentType = kAudioUnitType_Effect;
	cd.componentSubType = kAudioUnitSubType_PeakLimiter;  

	__Require_noErr (result = AUGraphAddNode (outGraph, &cd, &limiterNode), home);

	cd.componentType = kAudioUnitType_Output;
	cd.componentSubType = kAudioUnitSubType_DefaultOutput;  
	__Require_noErr (result = AUGraphAddNode (outGraph, &cd, &outNode), home);
	
	__Require_noErr (result = AUGraphOpen (outGraph), home);
	
	__Require_noErr (result = AUGraphConnectNodeInput (outGraph, synthNode, 0, limiterNode, 0), home);
	__Require_noErr (result = AUGraphConnectNodeInput (outGraph, limiterNode, 0, outNode, 0), home);
	
	// ok we're good to go - get the Synth Unit...
	__Require_noErr (result = AUGraphNodeInfo(outGraph, synthNode, 0, &outSynth), home);

  // ok we're set up to go - initialize and start the outGraph
  __Require_noErr(result = AUGraphInitialize(outGraph), home);

    CAShow(outGraph); // prints out the outGraph so we can see what it looks like...

  __Require_noErr(result = AUGraphStart(outGraph), home);

home:
  if (result == noErr)
    std::cout << "CAppleMidiSynth() success\n";
  else
    std::cout << "Failed to construct CAppleMidiSynth()\n";
}

CAppleMidiSynth::~CAppleMidiSynth()
{
  if (outGraph)
  {
    AUGraphStop (outGraph);
    DisposeAUGraph (outGraph);
  }
}

void CAppleMidiSynth::send(uint32_t waitTm, uint8_t st, uint8_t d1, uint8_t d2)
{
  // Called by the next two functions
  // waitTm is calculated by them
  CDelayMs d(waitTm, false);
  MusicDeviceMIDIEvent(outSynth, st, d1, d2, 0);
}

void CAppleMidiSynth::send(const CMidiPacket &mp)
{
    static uint32_t prevTm{0};
    uint32_t ms_delay = mp.get_timestamp() - prevTm;
    CAppleMidiSynth::send(ms_delay, mp.get_status(), mp.get_data1(), mp.get_data2());
    prevTm = mp.get_timestamp();
}

void CAppleMidiSynth::send(const std::vector<CMidiPacket> &vmp)
{
    for (auto itr : vmp) {
        CAppleMidiSynth::send(itr);
    }
}