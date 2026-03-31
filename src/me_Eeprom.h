// EEPROM memory access

/*
  Author: Martin Eden
  Last mod.: 2026-03-31
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_Eeprom
{
  void Init();
  TBool Get(TUnit * Data, TAddress Address);
  TBool Put(TUnit Data, TAddress Address);

  namespace Description
  {
    const TAddress MaxAddress = 1024 - 1;

    TBool IsValidAddress(TAddress);
  }

  namespace Core
  {
    void Init();
    void Get(TAddress DataPtr, TAddress);
    void Put(TAddress DataPtr, TAddress);
  }
}

/*
  2025-07-12
  2025-07-13
  2025-08-29
  2026-03-31
*/
