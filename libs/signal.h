#ifndef _SIGNAL_H_
#define _SIGNAL_H_

#include <string>
#include <vector>

class Signal
{
  private:
    unsigned int columns_count, lines_count;
    std::vector<std::vector<float>> data;


  public:
    Signal();
    Signal(std::string json_config_file_name);
    Signal(Signal& other);

    Signal(const Signal& other);
    virtual ~Signal();

    Signal& operator= (Signal& other);
    Signal& operator= (const Signal& other);

  protected:
    void copy(Signal& other);
    void copy(const Signal& other);

  public:
    void load(std::string json_config_file_name);
    unsigned int get_columns_count();
    unsigned int get_lines_count();

    
};

#endif


/*


class RuleOfThree
{
  public:
    // Default constructor
    RuleOfThree();

    // Copy constructor
    RuleOfThree(RuleOfThree& other);

    // Copy constructor
    RuleOfThree(const RuleOfThree& other);

    // Destructor
    virtual ~RuleOfThree();

    // Copy assignment operator
    RuleOfThree& operator= (RuleOfThree& other);

    // Copy assignment operator
    RuleOfThree& operator= (const RuleOfThree& other);

  protected:
    void copy(RuleOfThree& other);
    void copy(const RuleOfThree& other);
};

*/
