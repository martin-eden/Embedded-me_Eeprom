// EEPROM memory access

/*
  Author: Martin Eden
  Last mod.: 2025-08-29
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_Eeprom
{
  // Initialize. Optional
  void Init();

  // Read byte
  TBool Get(TUnit * Data, TAddress Address);

  // Write byte
  TBool Put(TUnit Data, TAddress Address);
}

/*
  2025-07-12
  2025-07-13
  2025-08-29
*/
