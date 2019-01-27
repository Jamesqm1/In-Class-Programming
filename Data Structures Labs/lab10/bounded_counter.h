


#pragma once
     
#include "int_counter.h"

class bounded_counter : public int_counter {
public:
    bounded_counter()                   { _value = 0; _bound=100;   }
    bounded_counter(unsigned int b)   { _value=0; _bound=b;         }
    virtual void increment()        { if(_value!=_bound) _value++; }
    virtual void reset()            { _value = 0; }
    virtual std::string to_string() { return std::to_string(_value); }
protected:
    unsigned int _value;

private:
    unsigned int _bound;
};