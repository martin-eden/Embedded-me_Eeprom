// EEPROM access

/*
  Author: Martin Eden
  Last mod.: 2025-08-29
*/

#include <me_Eeprom.h>

#include <me_Eeprom_Bare.h>

#include <avr/interrupt.h> // for cli()

using namespace me_Eeprom;

const TAddress MaxAddress = 1024 - 1;

/*
  [Internal] Check that address makes sense
*/
TBool IsValidAddress(
  TAddress Address
)
{
  return (Address <= MaxAddress);
}

/*
  Initialize. Optional

  We're making sure that writes really write data, not erasing or
  zero-saturating it. Also we're disabling interrupt signal when
  EEPROM is available.

  After reset, write mode is correct. And interrupt is disabled.
  Only case of calling this routine if someone else has changed
  that settings.
*/
void me_Eeprom::Init()
{
  using
    me_Eeprom_Bare::Eeprom,
    me_Eeprom_Bare::TWriteMode;

  Eeprom->Control.WriteMode = (TUint_1) TWriteMode::Replace;

  Eeprom->Control.EnableIdleSignal = false;
}

/*
  Read byte
*/
TBool me_Eeprom::Get(
  TUnit * Data,
  TAddress Address
)
{
  using me_Eeprom_Bare::Eeprom;

  if (!IsValidAddress(Address)) return false;

  while (Eeprom->Control.IsWriting);

  Eeprom->Address = Address;

  Eeprom->Control.IsReading = true;

  while (Eeprom->Control.IsReading);

  *Data = Eeprom->Data;

  return true;
}

/*
  Write byte
*/
TBool me_Eeprom::Put(
  TUnit Data,
  TAddress Address
)
{
  using me_Eeprom_Bare::Eeprom;

  if (!IsValidAddress(Address)) return false;

  while (Eeprom->Control.IsWriting);

  Eeprom->Address = Address;

  Eeprom->Data = Data;

  TUnit OrigSreg = SREG;
  cli();

  Eeprom->Control.GoingToWriteSeriously = true;
  Eeprom->Control.IsWriting = true;

  SREG = OrigSreg;

  while (Eeprom->Control.IsWriting);

  return true;
}

/*
  2025-07-12
  2025-07-13
  2025-08-29
*/
