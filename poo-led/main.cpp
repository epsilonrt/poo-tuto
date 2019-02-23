// POO Tutorial
// Led Class Demo

// Use of the Led class

// Created on February 23, 2019

// This example code is in the public domain.
#ifdef __unix__
#include <Piduino.h>  // All the magic is here ;-)
#else
// Defines the serial port as the console on the Arduino platform
#define Console Serial
#endif

#include "poo-led.h"

// <DANGER> Be careful !!! Before launching this program :
//    -> Check that the pin below is well connected to an LED ! <-
Led led (0, false); // Header Pin 11: GPIO17 for RPi, GPIOA0 for NanoPi

void setup() {

  Console.begin (115200);
  // initialize the led
  led.begin ();
}

void loop () {
  // Press Ctrl+C to abort ...

  for (int i = 0; i < 8; i++) {
    led.write (true);
    if (led.read() == true) {
      Console.println ("+");
    }
    else {
      Console.println ("!");
    }
    delay (100);

    led.write (false);
    if (led.read() == false) {
      Console.println ("-");
    }
    else {
      Console.println ("!");
    }
    delay (400);
  }
  Console.println();

  for (int i = 0; i < 8; i++) {

    led.toggle();
    delay (500);
  }
}
