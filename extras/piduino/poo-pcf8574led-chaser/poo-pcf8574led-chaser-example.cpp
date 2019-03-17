// POO Tutorial
// Chaser Class Demo

// This program helps to check the class.

// The chase runs with default values for 10s,
// then the lighting delay is changed to 500ms for 10s,
// then the direction of operation is reversed for 10s,
// before being stopped for 10s, and it starts again.

// This program can be compiled on Arduino and with Piduino on Pi boards.

// Created on February 23, 2019

// This example code is in the public domain.
#ifdef __unix__
#include <Piduino.h>  // All the magic is here ;-)
#else
// Defines the serial port as the console on the Arduino platform
#define Console Serial
#endif

#include "poo-pcf8574led.h"
#include "poo-chaser.h"

// Function prototypes
void printChaserStatus (unsigned long maxtime);
void chaserFor (unsigned long maxtime);

// <<<< ----> settings below to be modified according to your wiring <----- >>>>
TwoWire Wire2; // the PCF8574 is connected on the i2c-2 bus
Pcf8574 pcf8574 (0x20, Wire2);
const int nofLeds = 5;
Pcf8574Led leds[nofLeds] = {
  Pcf8574Led (pcf8574, 0),
  Pcf8574Led (pcf8574, 1),
  Pcf8574Led (pcf8574, 2),
  Pcf8574Led (pcf8574, 3),
  Pcf8574Led (pcf8574, 4)
};
// <<<< ---->               End of the settings                      <----- >>>>
// -----------------------------------------------------------------------------

Chaser chaser (leds, nofLeds);

void setup() {

  Console.begin (115200);
  Wire2.begin (2);
  pcf8574.begin();
  chaser.begin ();
}

void loop () {
  // Press Ctrl+C to abort ...

  chaserFor (10000);

  chaser.setDelay (500);
  chaserFor (10000);

  chaser.setSense (Chaser::Left);
  chaserFor (10000);

  chaser.setOn (false);
  chaserFor (10000);

  chaser.setDelay (100);
  chaser.setSense (Chaser::Right);
  chaser.setOn (true);
}

void printChaserStatus (unsigned long maxtime) {

  if (chaser.on()) {

    Console.print ("Chaser On, to the ");
    Console.print (chaser.sense() == Chaser::Right ? "right" : "left");
    Console.print (" with a lighting time of ");
    Console.print (chaser.delay());
    Console.print (" ms");
  }
  else {

    Console.print ("Chaser Off");
  }
  Console.print (", for a time of ");
  Console.print (maxtime);
  Console.println (" ms.");
}

void chaserFor (unsigned long maxtime) {

  printChaserStatus (maxtime);
  unsigned long t = millis();
  while ( (millis() - t) < maxtime) {
    chaser.poll();
  }
}
