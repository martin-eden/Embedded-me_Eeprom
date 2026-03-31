// EEPROM checkers

/*
  Author: Martin Eden
  Last mod.: 2026-03-31
*/

#include <me_Eeprom.h>

using namespace me_Eeprom;

/*
  Check that address makes sense
*/
TBool me_Eeprom::Description::IsValidAddress(
  TAddress Address
)
{
  return (Address <= Description::MaxAddress);
}

/*
  2026-03-31
*/
