#ifndef _SIGNAL_FILE_WRITE_H_
#define _SIGNAL_FILE_WRITE_H_

#include <signal.h>
#include <log.h>

class SignalFileWrite: public Signal
{
  private:
    Log output_log;

  public:
    SignalFileWrite();
    SignalFileWrite(std::string file_name);
    SignalFileWrite(SignalFileWrite& other);

    SignalFileWrite(const SignalFileWrite& other);
    virtual ~SignalFileWrite();

    SignalFileWrite& operator= (SignalFileWrite& other);
    SignalFileWrite& operator= (const SignalFileWrite& other);

  protected:
    void copy_fw(SignalFileWrite& other);
    void copy_fw(const SignalFileWrite& other);

  public:
    void add_next(std::vector<float> &v);
};

#endif
