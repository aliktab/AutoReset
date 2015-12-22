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


// Initialization

void setup()
{
  // Initializeline pins mode, value, state and timer.
  for (int idx = 0; idx < sizeof(PIN_FAN) / sizeof(uint8_t); idx++)
  {
    pinMode(PIN_FAN[idx], OUTPUT);
    digitalWrite(PIN_FAN[idx], LOW);
  }

  // Initialize time system.
  start_time = millis();
  mode_time = 0;
}


// Main Loop

void loop()
{

}




