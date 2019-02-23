#pragma once

class Led {
  public:
    Led (int pin, bool activeState = true);
    void begin ();
    bool read() const;
    void write (bool on);
    void toggle();
    int pin() const;
    bool activeState() const;
  private:
    int m_pin;
    bool m_state;
};
