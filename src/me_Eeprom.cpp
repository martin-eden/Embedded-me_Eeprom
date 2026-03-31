// EEPROM access

/*
  Author: Martin Eden
  Last mod.: 2026-03-31
*/

#include <me_Eeprom.h>

using namespace me_Eeprom;

/*
  Initialize
*/
void me_Eeprom::Init()
{
  Core::Init();
}

/*
  Read byte
*/
TBool me_Eeprom::Get(
  TUnit * Data,
  TAddress Address
)
{
  if (!Description::IsValidAddress(Address))
    return false;

  Core::Get(TAddress(Data), Address);

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
  if (!Description::IsValidAddress(Address))
    return false;

  Core::Put(TAddress(&Data), Address);

  return true;
}

/*
  2025-07-12
  2025-07-13
  2025-08-29
  2026-03-31
*/
