#ifndef _SIGNAL_FILE_READ_H_
#define _SIGNAL_FILE_READ_H_

#include <signal.h>

class SignalFileRead: public Signal
{
  protected:
    unsigned int              offset, stride;
    std::vector<unsigned int> columns_to_read;

  public:
    SignalFileRead();
    SignalFileRead(std::string json_config_file_name);
    SignalFileRead(SignalFileRead& other);

    SignalFileRead(const SignalFileRead& other);
    virtual ~SignalFileRead();

    SignalFileRead& operator= (SignalFileRead& other);
    SignalFileRead& operator= (const SignalFileRead& other);

  protected:
    void copy_fr(SignalFileRead& other);
    void copy_fr(const SignalFileRead& other);

  public:
    void load(std::string json_config_file_name);

  private:
    void load_file(std::string file_name);
};

#endif
