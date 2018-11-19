#include "signal_file_read.h"
#include <json_config.h>

#include <iostream>
#include <fstream>
#include <sstream>


SignalFileRead::SignalFileRead()
               :Signal()
{

}

SignalFileRead::SignalFileRead(std::string json_config_file_name)
               :Signal()
{
  load(json_config_file_name);
}

SignalFileRead::SignalFileRead(SignalFileRead& other)
               :Signal(other)
{
  copy_fr(other);
}


SignalFileRead::SignalFileRead(const SignalFileRead& other)
               :Signal(other)
{
  copy_fr(other);
}

SignalFileRead::~SignalFileRead()
{

}

SignalFileRead& SignalFileRead::operator= (SignalFileRead& other)
{
  copy_fr(other);
  copy(other);
  return *this;
}

SignalFileRead& SignalFileRead::operator= (const SignalFileRead& other)
{
  copy_fr(other);
  copy(other);
  return *this;
}

void SignalFileRead::copy_fr(SignalFileRead& other)
{
  offset = other.offset;
  stride = other.stride;

  columns_to_read = other.columns_to_read;
}

void SignalFileRead::copy_fr(const SignalFileRead& other)
{
  offset = other.offset;
  stride = other.stride;

  columns_to_read = other.columns_to_read;
}

void SignalFileRead::load(std::string json_config_file_name)
{
  JsonConfig json(json_config_file_name);

  std::string dat_file_name = json.result["dat_file_name"].asString();

  offset = json.result["offset"].asInt();
  stride = json.result["stride"].asInt();

  columns_to_read.clear();
  for (unsigned int i = 0; i < json.result["columns_to_read"].size(); i++)
    columns_to_read.push_back(json.result["columns_to_read"][i].asInt());

  load_file(dat_file_name);
}

void SignalFileRead::load_file(std::string file_name)
{
  for (unsigned int i = 0; i < data.size(); i++)
    data[i].clear();

  data.clear();
  data.resize(columns_to_read.size());

  std::ifstream file(file_name);

  if (file.is_open() != true)
  {
    std::cout << "ERROR, file " << file_name << " opening error\n";
    return;
  }

  std::string line;

  unsigned int line_ptr = 0;

  while (std::getline(file, line))
  {
    std::stringstream iss(line);

    float value;
    std::vector<float> line_f;
    while (iss >> value)
    {
      line_f.push_back(value);
    }

    if (line_ptr >= offset)
    if ((line_ptr%stride) == 0)
    {
      std::vector<float> result_line;

      for (unsigned int i = 0; i < columns_to_read.size(); i++)
      {
        unsigned int idx = columns_to_read[i];
        result_line.push_back(line_f[idx]);
      }

      data.push_back(result_line);
    }

    line_ptr++;
  }
}
