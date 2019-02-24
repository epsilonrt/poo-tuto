// POO Tutorial
// SwitchInt Class Demo

// This program helps to check the class.

// It waits for the push button to be pressed and toggles the lighting of the 
// led with each press.
// 
// The class runs in interrupt which consumes no CPU time on Pi board.

// This program can be compiled only with Piduino on Pi boards.

// Created on February 23, 2019

// This example code is in the public domain.
#ifdef __unix__
#include <Piduino.h>  // All the magic is here ;-)
#else
// Defines the serial port as the console on the Arduino platform
#define Console Serial
#endif

#include "poo-led.h"
#include "poo-switch-int.h"

// Function prototypes
void swIsr (void * unused);

// <<<< ----> settings below to be modified according to your wiring <----- >>>>
// -----------------------------------------------------------------------------
// <DANGER> Be careful !!! Before launching this program :
//    -> Check that the pin below is well connected to an LED ! <-
// Pin 0, Low level lights the led > Header Pin 11, GPIO17 on RPi, GPIOA0 on NPi
Led led (0, false);

// Pin 3 > Header Pin 15, GPIO22 on RPi, GPIOA3 on NPi
SwitchInt sw (3);
// <<<< ---->               End of the settings                      <----- >>>>
// -----------------------------------------------------------------------------

void setup() {

  led.begin ();
  sw.begin (swIsr, RISING);
}

void loop () {
  // Press Ctrl+C to abort ...

  // endless sleep, the process is woken up by interrupts.
  delay (-1);
}

void swIsr (void * unused) {
  led.toggle();
}
