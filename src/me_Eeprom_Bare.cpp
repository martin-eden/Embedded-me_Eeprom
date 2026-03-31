// Linking of EEPROM layout

/*
  Author: Martin Eden
  Last mod.: 2026-03-31
*/

#include <me_Eeprom_Bare.h>

using namespace me_Eeprom_Bare;

// Linking "extern" structure to address
TEeprom * me_Eeprom_Bare::Eeprom = (TEeprom *) 63;

/*
  2026-03-31
*/
