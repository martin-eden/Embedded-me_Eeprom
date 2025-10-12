// EEPROM layout

/*
  Author: Martin Eden
  Last mod.: 2025-10-12
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_Eeprom_Bare
{
  // Fanciness. Write modes
  enum struct TWriteMode
  {
    Replace = 0,
    Erase = 1,
    AddZeroes = 2,
  };

  // Control/State panel
  struct TControl
  {
    volatile TBool IsReading : 1;    // 1
    volatile TBool IsWriting : 1;    // 2
    TBool GoingToWriteSeriously : 1; // 3
    TBool EnableIdleSignal : 1;      // 4
    TUint_1 WriteMode : 2;           // 5 6
    TUint_1 : 2;                     // 7 8
  };

  // EEPROM layout
  struct TEeprom
  {
    // 1 Panel
    TControl Control;
    // 2 Data
    TUint_1 Data;
    // 3 4 Address
    TUint_2 Address : 10;
    TUint_1 : 6;
    // 5 --
  };

  // Mapping layout to address
  TEeprom * Eeprom = (TEeprom *) 63;
}

/*
  2025-07-13
*/
