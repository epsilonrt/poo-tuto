#pragma once

#include "poo-chaser.h"
#include "poo-switch.h"

class ChaserSwitch : public Chaser {

  public:
    static const int nofButtons = 3; // 0: on, 1: sense, 2: delay
    typedef void (* ChangedHandler) (ChaserSwitch & chaser);

    ChaserSwitch (Led * leds, int nofLeds);
    ChaserSwitch (Led * leds, int nofLeds, Switch buttons[]);
    void begin ();
    void poll();
    int stepDelay() const;
    void setStepDelay (int value);
    int minDelay() const;
    int maxDelay() const;
    void setMinDelay (int value);
    void setMaxDelay (int value);
    ChangedHandler changedHandler() const;
    void setChangedHandler (ChangedHandler handler);
    void callChangedHandler();

  private:
    Switch * m_buttons;
    int m_min_delay;
    int m_max_delay;
    int m_step_delay;
    ChangedHandler m_handler;

    static void onHandler (void * chaser);
    static void senseHandler (void * chaser);
    static void delayHandler (void * chaser);
};
