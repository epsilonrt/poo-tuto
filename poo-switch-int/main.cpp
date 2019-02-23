// Blink

// Turns an LED on for one second, then off for one second, repeatedly.

// Created 8 March 2018

// This example code is in the public domain.
#ifdef __unix__
#include <Piduino.h>  // All the magic is here ;-)
#else
// Defines the serial port as the console on the Arduino platform
#define Console Serial
#endif

#include "poo-led.h"
#include "poo-switch-int.h"

// <DANGER> Be careful !!! Before launching this program :
//    -> Check that the pin below is well connected to an LED ! <-
Led led (0, false); // Header Pin 11: GPIO17 for RPi, GPIOA0 for NanoPi
SwitchInt sw (3); // Header Pin 15: GPIO22 for RPi, GPIOA3 for NanoPi

void swIsr (void * unused);

void setup() {

  led.begin ();
  sw.begin (swIsr, RISING);
}

void loop () {
  // Press Ctrl+C to abort ...
  delay (-1);
}

void swIsr (void * unused) {
  led.toggle();
}
