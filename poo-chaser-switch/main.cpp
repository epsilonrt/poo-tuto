// POO Tutorial
// ChaserSwitch Class Demo

// This program helps to check the class.

// The chaser runs with default values.
// The push buttons allow you to change the settings:
// - Button 1 allows you to stop and start the caterpillars.
// - Button 2 reverses the direction of operation.
// - Button 3 is used to change the duration of illumination.
// Each change is displayed on the console.

// This program can be compiled on Arduino and with Piduino on Pi boards.

// Created on February 23, 2019

// This example code is in the public domain.
#ifdef __unix__
#include <Piduino.h>  // All the magic is here ;-)
#else
// Defines the serial port as the console on the Arduino platform
#define Console Serial
#endif

#include "poo-pinled.h"
#include "poo-chaser-switch.h"

// Function prototypes
void printChaserStatus (ChaserSwitch & c);

// <<<< ----> settings below to be modified according to your wiring <----- >>>>
// -----------------------------------------------------------------------------
// <DANGER> Be careful !!! Before launching this program :
//    -> Check that the pins below is well connected to LEDs ! <-
// Pin 0, Low level lights the led > Header Pin 11, GPIO17 on RPi, GPIOA0 on NPi
// Pin 1, Low level lights the led > Header Pin 12, GPIO18 on RPi, GPIOA6 on NPi
// Pin 2, Low level lights the led > Header Pin 13, GPIO27 on RPi, GPIOA2 on NPi
const int nofLeds = 3;
PinLed leds[nofLeds] = { PinLed (0, false), PinLed (1, false), PinLed (2, false) };

// Pin 3 > Header Pin 15, GPIO22 on RPi, GPIOA3 on NPi
// Pin 4 > Header Pin 16, GPIO23 on RPi, GPIOG8 on NPi
// Pin 5 > Header Pin 18, GPIO24 on RPi, GPIOG9 on NPi
Switch buttons[] = { Switch (3), Switch (4), Switch (5) };
// <<<< ---->               End of the settings                      <----- >>>>
// -----------------------------------------------------------------------------

ChaserSwitch chaser (leds, nofLeds, buttons);

void setup() {

  Console.begin (115200);
  chaser.setChangedHandler (printChaserStatus);
  chaser.begin ();
}

void loop () {
  // Press Ctrl+C to abort ...

  chaser.poll();
}

void printChaserStatus (ChaserSwitch & c) {

  Console.print (c.on() ? "On" : "Off");
  Console.print (", to the ");
  Console.print (c.sense() == Chaser::Right ? "right" : "left");
  Console.print (" with ");
  Console.print (c.delay());
  Console.println (" ms delay.");
}
