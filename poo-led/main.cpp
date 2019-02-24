// POO Tutorial
// Led Class Demo

// This program helps to check the class.

// It blinks the LED by lighting it for 100 ms then turning it off for 400 ms. 
// At each step, it checks that the value read corresponds to the value written 
// and displays a '+' then a '-' on the console. In case of error a '!' is printed.
// Then we use the toggle function to flash the led (500/500), then start again.

// This program can be compiled on Arduino and with Piduino on Pi boards.

// Created on February 23, 2019

// This example code is in the public domain.
#ifdef __unix__
#include <Piduino.h>  // All the magic is here ;-)
#else
// Defines the serial port as the console on the Arduino platform
#define Console Serial
#endif

#include "poo-led.h"

// <<<< ----> settings below to be modified according to your wiring <----- >>>>
// -----------------------------------------------------------------------------
// <DANGER> Be careful !!! Before launching this program :
//    -> Check that the pin below is well connected to an LED ! <-
// Pin 0, Low level lights the led > Header Pin 11, GPIO17 on RPi, GPIOA0 on NPi
Led led (0, false);
// <<<< ---->               End of the settings                      <----- >>>>
// -----------------------------------------------------------------------------

void setup() {

  Console.begin (115200);
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
