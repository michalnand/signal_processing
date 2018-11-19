#ifndef _MAGNETIC_EVENT_GENERATOR_H_
#define _MAGNETIC_EVENT_GENERATOR_H_

#include <vector>

class MagneticEventGenerator
{
  private:
    unsigned int state;
    unsigned int id;

  private:
    float event_probability;
    float noise_level      ;
    unsigned int event_duration_min;
    unsigned int event_duration_max;
    unsigned int event_duration;
    float detection_jitter;

    unsigned int event_mark, event_ptr;

    float min_amplitude, max_amplitude;
    float ax, ay, az;
    float phase;

    float phase_x, phase_y, phase_z;

  public:
    MagneticEventGenerator();
    virtual ~MagneticEventGenerator();

    std::vector<float> get_next();

    unsigned int get_event_duration_min();
    unsigned int get_event_duration_max();

  private:
    float rnd(float min = 0.0, float max = 1.0);
    float sgn(float x);

};


#endif
