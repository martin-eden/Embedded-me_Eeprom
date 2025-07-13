// EEPROM read-write

/*
  Author: Martin Eden
  Last mod.: 2025-07-13
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_Eeprom
{
  // ( Capacity and span constants
  const TUint_2 Size = 1024;

  const TAddress
    MinAddress = 0,
    MaxAddress = Size - 1;
  // )

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
*/
