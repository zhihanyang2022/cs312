#ifndef CVOLUMECONTROLLER_H_
#include "CVolumeController.h"
#endif

#ifndef HW511_CBLUESMELODYTRACK_H_
#include "hw511_CBluesMelodyTrack.h"
#endif

#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>

#define PI 3.14159265

CVolumeController::CVolumeController()
{
}

double CVolumeController::get_volume_step_size(uint32_t begin_tm, uint32_t end_tm, int begin_volume, int end_volume) {
    double duration = end_tm - begin_tm;  // so that end_volume - begin_volume also gets converted to double
    // std::cout << duration << std::endl;
    double volume_step_size = (end_volume - begin_volume) / duration * 10;
    // std::cout << volume_step_size << std::endl;
    return volume_step_size;
}

void CVolumeController::linearly_interpolate(CBluesMelodyTrack * track, uint32_t begin_tm, uint32_t end_tm, int begin_volume, int end_volume, std::vector<int> offsets) {
    
    double volume_step_size = get_volume_step_size(begin_tm, end_tm, begin_volume, end_volume);
    double volume_step_num = (end_volume - begin_volume) / volume_step_size;
    double timestamp_step_size = (end_tm - begin_tm) / volume_step_num;

    if (offsets.size() == 0) {
        offsets = std::vector<int>(volume_step_num, 0);
    }

    double current_timestamp = begin_tm + timestamp_step_size;
    double current_volume = begin_volume + volume_step_size;
    int offset_idx = 0;
    if (begin_volume <= end_volume) {
        
        while(current_volume <= end_volume) {
            track->push_volume(current_timestamp, track->get_channel(), current_volume+offsets.at(offset_idx));
            current_timestamp += timestamp_step_size;
            current_volume += volume_step_size;
            offset_idx += 1;
        }

    } else {  // use negative increment
        
        while(current_volume > end_volume) {
            track->push_volume(current_timestamp, track->get_channel(), current_volume+offsets.at(offset_idx));
            current_timestamp += timestamp_step_size;
            current_volume += volume_step_size;
            offset_idx += 1;
        }
    }
}

void CVolumeController::wiggly_interpolate(CBluesMelodyTrack * track, uint32_t begin_tm, uint32_t end_tm, int begin_volume, int end_volume, int num_oscillations, int amplitude) {
    double volume_step_size = get_volume_step_size(begin_tm, end_tm, begin_volume, end_volume);
    double volume_step_num = (end_volume - begin_volume) / volume_step_size;
    double f = num_oscillations / volume_step_num * 2 * PI;
    
    std::vector<int> offsets;
    for (int i = 0; i < volume_step_num; i++) {
        int offset = amplitude * sin(f * i);
        if (offset < 0) {
            offset = 0;
        }
        offsets.push_back(offset);
    }
    linearly_interpolate(track, begin_tm, end_tm, begin_volume, end_volume, offsets);
}
