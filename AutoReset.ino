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

const uint8_t PIN_ONOFF  = 0x1;
const uint8_t PIN_PING   = 0x2;
const uint8_t PIN_RESET  = 0x0;

const time_t PING_TIMEOUT = 9 * 1000;

time_t curr_time = 0;
time_t ping_time = 0;

// Initialization

void setup()
{
  // Initializeline pins mode, value, state and timer.
  pinMode(PIN_ONOFF, INPUT);
  pinMode(PIN_PING, INPUT);

  pinMode(PIN_RESET, OUTPUT);
  digitalWrite(PIN_RESET, HIGH);

  // Initialize time system.
  setTime(0);
  ping_time = now();
}


// Main Loop

void loop()
{
  if (HIGH == digitalRead(PIN_ONOFF))
  {
    if (HIGH == digitalRead(PIN_PING))
      ping_time = now();
  }
  else
    ping_time = now();

  digitalWrite(PIN_RESET, (now() - ping_time < PING_TIMEOUT) ? HIGH : LOW);
}




