#include "signal.h"


Signal::Signal()
{
  columns_count = 0;
  lines_count   = 0;
  current_ptr   = 0;
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
  data          = other.data;
  current_ptr   = other.current_ptr;
}

void Signal::copy(const Signal& other)
{
  columns_count = other.columns_count;
  lines_count   = other.lines_count;
  data          = other.data;
  current_ptr   = other.current_ptr;
}

unsigned int Signal::get_columns_count()
{
  return columns_count;
}

unsigned int Signal::get_lines_count()
{
  return lines_count;
}

void Signal::rewind()
{
  current_ptr = 0;
}

bool Signal::is_end()
{
  if (current_ptr >= lines_count)
    return true;

  return false;
}

std::vector<float>& Signal::get(unsigned int line)
{
  return data[line];
}

std::vector<float>& Signal::get_next()
{
  return data[current_ptr++];
}

void Signal::add_next(std::vector<float>& v)
{
  data.push_back(v);
  lines_count++;
}
