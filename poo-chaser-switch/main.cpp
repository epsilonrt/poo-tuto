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

#include "poo-chaser.h"

// <DANGER> Be careful !!! Before launching this program :
//    -> Check that the pins below is well connected to LEDs ! <-
// Pin 0 > Header Pin 11, GPIO17 for RPi, GPIOA0 for NanoPi
// Pin 1 > Header Pin 12, GPIO18 for RPi, GPIOA6 for NanoPi
// Pin 2 > Header Pin 13, GPIO27 for RPi, GPIOA2 for NanoPi
Led leds[] = { Led (0, false), Led (1, false), Led (2, false) };
Chaser chaser (leds, 3);

void printChaserStatus (unsigned long maxtime);
void chaserFor (unsigned long maxtime);

void setup() {

  Console.begin (115200);
  // initialize the led
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
