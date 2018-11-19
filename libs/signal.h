#ifndef _SIGNAL_H_
#define _SIGNAL_H_

#include <string>
#include <vector>

class Signal
{
  protected:
    unsigned int                    columns_count, lines_count;
    std::vector<unsigned int>       columns_to_read;
    std::vector<std::vector<float>> data;

    unsigned int current_ptr;

  public:
    Signal();
    Signal(Signal& other);

    Signal(const Signal& other);
    virtual ~Signal();

    virtual Signal& operator= (Signal& other);
    virtual Signal& operator= (const Signal& other);

  protected:
    void copy(Signal& other);
    void copy(const Signal& other);

  public:
    unsigned int get_columns_count();
    unsigned int get_lines_count();

    virtual void rewind();
    virtual bool is_end();
    virtual std::vector<float>& get(unsigned int line);

    virtual std::vector<float>& get_next();
    virtual void add_next(std::vector<float>& v);
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
