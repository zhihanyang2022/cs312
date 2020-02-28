#ifndef VOLUMECONTROLLER_H_
#define VOLUMECONTROLLER_H_

#ifndef HW511_CBLUESMELODYTRACK_H_
#include "hw511_CBluesMelodyTrack.h"
#endif

#include <vector>

class CVolumeController
{
public:

  CVolumeController();

  double get_volume_step_size(uint32_t begin_tm, uint32_t end_tm, int begin_volume, int end_volume);

  void linearly_interpolate(CBluesMelodyTrack * track, uint32_t begin_tm, uint32_t end_tm, int begin_volume, int end_volume, std::vector<int> offsets = {});
  
  void wiggly_interpolate(CBluesMelodyTrack * track, uint32_t begin_tm, uint32_t end_tm, int begin_volume, int end_volume, int num_oscillations, int amplitude);

};

#endif // VOLUMECONTROLLER_H_