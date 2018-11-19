#include <libs.h>
#include <signal_file_write.h>
#include <magnetic_event_generator.h>


int main()
{
  srand(time(NULL)); 

  SignalFileWrite sig("output.log");
  MagneticEventGenerator mag;

  unsigned int samples_count = 1000;
  for (unsigned int i = 0; i < samples_count; i++)
  {
    auto res = mag.get_next();
    sig.add_next(res);
  }

  return 0;
}
