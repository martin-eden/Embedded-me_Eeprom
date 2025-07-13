// EEPROM layout

/*
  Author: Martin Eden
  Last mod.: 2025-07-13
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
    volatile TBool IsReading : 1;
    volatile TBool IsWriting : 1;
    TBool GoingToWriteSeriously : 1;
    TBool EnableIdleSignal : 1;
    TUint_1 WriteMode : 2;
    TUint_1 : 2;
  };

  // EEPROM layout
  struct TEeprom
  {
    // 1 Panel
    TControl Control;
    // 2 Data
    TUint_1 Data;
    // 3 Address
    TUint_2 Address : 10;
    TUint_1 : 6;
  };

  // Mapping layout to address
  TEeprom * Eeprom = (TEeprom *) 63;
}

/*
  2025-07-13
*/
