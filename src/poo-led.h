#pragma once

#include <Arduino.h>

class Led {
  public:
    Led (bool activeState = true);
    virtual ~Led();
    virtual void begin () = 0;
    virtual void write (bool on) = 0;
    virtual bool read() const { return false; }
    virtual void toggle() { write (!read()); }
    inline bool activeState() const { return m_state; }

    virtual size_t size () const = 0;
    Led * arrayItem (int i, Led * array = 0);
  private:
    bool m_state;
};
