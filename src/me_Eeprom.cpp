// EEPROM access

/*
  Author: Martin Eden
  Last mod.: 2025-10-12
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
  Initialize

  We don't have to do anything here for now.
  This method is design placeholder.
*/
void me_Eeprom::Init()
{
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

  if (!IsValidAddress(Address))
    return false;

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

  if (!IsValidAddress(Address))
    return false;

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
