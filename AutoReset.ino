/*
  Auto Reset Controller.

  Copyright (c) 2014 Purple Wolf Ltd. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/


#include <PwCore.h>
#include <Time.h>

const uint8_t PIN_ONOFF  = 0x0;
const uint8_t PIN_PING   = 0x2;
const uint8_t PIN_RESET  = 0x1;

const time_t PING_TIMEOUT = 15;
const time_t RESET_PAUSE  = 900;
const time_t CYCLE_PAUSE  = 10;

volatile time_t ping_time = 0;

// Initialization

void setup()
{
  // Initialize interrupts.
  cli();                                // disables interrupts
  GIMSK = 0b00100000;                   // turns on pin change interrupts
  PCMSK = 0b00000100 | (1 << PIN_PING); // turn on interrupts on pins PIN_PING
  sei();                                // enables interrupts

  // Initialize time system.
  setTime(0);
  ping_time = now();

  // Initializeline pins mode, value, state and timer.
  pinMode(PIN_ONOFF, INPUT);
  pinMode(PIN_PING, INPUT);

  pinMode(PIN_RESET, OUTPUT);
  digitalWrite(PIN_RESET, HIGH);
  delay(RESET_PAUSE);
  digitalWrite(PIN_RESET, LOW);
}


// Main Loop

void loop()
{
  if (LOW == digitalRead(PIN_ONOFF))
    ping_time = now();

  if (HIGH == digitalRead(PIN_PING))
    ping_time = now();

  if (now() - ping_time > PING_TIMEOUT)
  {
    digitalWrite(PIN_RESET, HIGH);
    delay(RESET_PAUSE);
    ping_time = now();
  }

  digitalWrite(PIN_RESET, LOW);
  delay(CYCLE_PAUSE);
}


// Hold interrupt on PING

ISR(PCINT0_vect)
{
  ping_time = now();
}



