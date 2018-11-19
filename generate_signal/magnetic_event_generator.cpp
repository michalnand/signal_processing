#include "magnetic_event_generator.h"

#include <iostream>
#include <stdlib.h>
#include <math.h>

MagneticEventGenerator::MagneticEventGenerator()
{
  id      = 0;
  state   = 0;

  event_probability   = 0.05;
  noise_level         = 0.25;
  event_duration_min  = 30;
  event_duration_max  = 150;

  detection_jitter = 0.25;

  min_amplitude = 0.5;
  max_amplitude = 1.0;
}

MagneticEventGenerator::~MagneticEventGenerator()
{

}


std::vector<float> MagneticEventGenerator::get_next()
{
  std::vector<float> result(6);

  float x     = rnd(-1.0, 1.0)*noise_level;
  float y     = rnd(-1.0, 1.0)*noise_level;
  float z     = rnd(-1.0, 1.0)*noise_level;
  float event = 0.0;
  float event_window = 0.0;

  float x_;
  float value_x, value_y, value_z;


  switch (state)
  {
    case 0:
           if (rnd() > event_probability)
           {
             state = 1;

             event_duration = rnd(event_duration_min, event_duration_max);

             event_ptr = 0;
             event_mark = event_duration*0.5 + event_duration*rnd(-detection_jitter*0.5, detection_jitter*0.5);

             ax = rnd(min_amplitude, max_amplitude);
             ay = rnd(min_amplitude, max_amplitude);
             az = rnd(min_amplitude, max_amplitude);

             float pi = 3.141592654;
             phase = rnd(-pi, pi);

             phase_x = 0.2*rnd(-pi, pi);
             phase_y = 0.2*rnd(-pi, pi);
             phase_z = 0.2*rnd(-pi, pi);
           }
           break;

    case 1:
            if (event_ptr == event_mark)
              event = 1.0;

            event_window = 1.0;

            x_ = event_ptr*1.0/event_duration;

            event_ptr++;

            value_x = exp(-(x_*x_))*sin(10.0*x_ + phase + phase_x);
            value_y = exp(-(x_*x_))*sin(10.0*x_ + phase + phase_y);
            value_z = exp(-(x_*x_))*sin(10.0*x_ + phase + phase_z);
            //value_ = sin(4.0*x_);

            x+= ax*value_x*(1.0 - noise_level);
            y+= ay*value_y*(1.0 - noise_level);
            z+= az*value_z*(1.0 - noise_level);

            if (event_ptr > event_duration)
              state = 2;
            break;

    case 2:
            event_ptr++;
            if (event_ptr > 2.0*event_duration_max)
              state = 0;
            break;
  }

  result[0] = id;
  result[1] = x;
  result[2] = y;
  result[3] = z;
  result[4] = event;
  result[5] = event_window;

  id++;

  return result;
}



float MagneticEventGenerator::rnd(float min, float max)
{
  float v = (rand()%10000000)/10000000.0;
  return v*(max - min) + min;
}

float MagneticEventGenerator::sgn(float x)
{
  if (x > 0.0)
    return 1.0;
  if (x < 0.0)
    return -1.0;
  return 0.0;
}
 

unsigned int MagneticEventGenerator::get_event_duration_min()
{
  return event_duration_min;
}

unsigned int MagneticEventGenerator::get_event_duration_max()
{
  return event_duration_max;
}
