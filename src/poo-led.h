#pragma once

class Led {
  public:
    Led (bool activeState = true);
    virtual ~Led();
    virtual void begin () = 0;
    virtual void write (bool on) = 0;
    virtual bool read() const { return false; }
    virtual void toggle() { write (!read()); }
    inline bool activeState() const {return m_state; }
  private:
    bool m_state;
};
