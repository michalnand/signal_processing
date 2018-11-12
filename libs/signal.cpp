#include "signal.h"


Signal::Signal()
{

}

Signal::Signal(std::string json_config_file_name)
{
  load(json_config_file_name);
}

Signal::Signal(Signal& other)
{
  copy(other);
}


Signal::Signal(const Signal& other)
{
  copy(other);
}

Signal::~Signal()
{

}

Signal& Signal::operator= (Signal& other)
{
  copy(other);
  return *this;
}

Signal& Signal::operator= (const Signal& other)
{
  copy(other);
  return *this;
}

void Signal::copy(Signal& other)
{
  columns_count = other.columns_count;
  lines_count   = other.lines_count;
  data = other.data;
}

void Signal::copy(const Signal& other)
{
  columns_count = other.columns_count;
  lines_count   = other.lines_count;
  data = other.data;
}

void Signal::load(std::string json_config_file_name)
{

}

unsigned int Signal::get_columns_count()
{
  return columns_count;
}

unsigned int Signal::get_lines_count()
{
  return lines_count;
}
