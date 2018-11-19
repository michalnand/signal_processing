#include "signal_file_write.h"


SignalFileWrite::SignalFileWrite()
               :Signal()
{

}

SignalFileWrite::SignalFileWrite(std::string file_name)
               :Signal()
{
  output_log.set_output_file_name(file_name);
}

SignalFileWrite::SignalFileWrite(SignalFileWrite& other)
               :Signal(other)
{
  copy_fw(other);
}


SignalFileWrite::SignalFileWrite(const SignalFileWrite& other)
               :Signal(other)
{
  copy_fw(other);
} 

SignalFileWrite::~SignalFileWrite()
{

}

SignalFileWrite& SignalFileWrite::operator= (SignalFileWrite& other)
{
  copy_fw(other);
  copy(other);
  return *this;
}

SignalFileWrite& SignalFileWrite::operator= (const SignalFileWrite& other)
{
  copy_fw(other);
  copy(other);
  return *this;
}

void SignalFileWrite::copy_fw(SignalFileWrite& other)
{
  output_log = other.output_log;
}

void SignalFileWrite::copy_fw(const SignalFileWrite& other)
{
  output_log = other.output_log;
}



void SignalFileWrite::add_next(std::vector<float> &v)
{
  for (unsigned int i = 0; i < v.size(); i++)
    output_log << v[i] << " ";
  output_log << "\n";
}
