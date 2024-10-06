#ifdef PIO_UNIT_TESTING
#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <Arduino.h> 

class Preferences {
    public:
    virtual void begin(String s, bool b);
    virtual void end(void);
    virtual String getString(String s1, String s2);
    virtual void putString(String s1, String s2);
};

#endif
#endif