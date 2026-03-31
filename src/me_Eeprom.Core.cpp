// EEPROM core functions

/*
  Author: Martin Eden
  Last mod.: 2026-03-31
*/

#include <me_Eeprom.h>

#include <me_Eeprom_Bare.h>
#include <me_Interrupts.h>

using namespace me_Eeprom;

using me_Eeprom_Bare::Eeprom;

/*
  Initialize
*/
void Core::Init()
{
  /*
    Calling this function is optional

    We're setting EEPROM write mode to Replace. But Replace is default
    mode after reset.
  */
  Eeprom->Control.WriteMode =
    (TUint_1) me_Eeprom_Bare::TWriteMode::Replace;
}

/*
  Read byte
*/
void Core::Get(
  TAddress DataPtr,
  TAddress Address
)
{
  while (Eeprom->Control.IsWriting);

  Eeprom->Address = Address;

  Eeprom->Control.IsReading = true;
  while (Eeprom->Control.IsReading);

  *(TUint_1 *) DataPtr = Eeprom->Data;
}

/*
  Write byte
*/
void Core::Put(
  TAddress DataPtr,
  TAddress Address
)
{
  while (Eeprom->Control.IsWriting);

  Eeprom->Address = Address;
  Eeprom->Data = *(TUint_1 *) DataPtr;

  {
    me_Interrupts::TInterruptsDisabler NoInts;

    Eeprom->Control.GoingToWriteSeriously = true;
    Eeprom->Control.IsWriting = true;
  }
  while (Eeprom->Control.IsWriting);
}

/*
  2025-07-12
  2025-07-13
  2025-08-29
  2026-03-31
*/
