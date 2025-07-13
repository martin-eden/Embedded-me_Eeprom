// [me_Eeprom] module test

/*
  Author: Martin Eden
  Last mod.: 2025-07-13
*/

/*
  Test reads and modifies EEPROM.

  In my Linux setup board is reset after ~3 seconds after opening.
  For that three seconds is starts to write new values to EEPROM
  but can not finish em all. So data map is jagged.
*/

#include <me_BaseTypes.h>
#include <me_Uart.h>
#include <me_Console.h>

#include <me_Eeprom.h>

/*
  Print EEPROM contents. Helper function
*/
void PrintEeprom()
{
  using namespace me_Eeprom;

  Console.Print("( Reading");

  for (TAddress Addr = MinAddress; Addr <= MaxAddress; ++Addr)
  {
    TUnit Byte;

    if (!Get(&Byte, Addr)) break;

    Console.Print(Byte);
  }

  Console.Print(")");
}

/*
  Zero EEPROM contents
*/
void ClearEeprom()
{
  using namespace me_Eeprom;

  Console.Write("( Clearing ");

  for (TAddress Addr = MinAddress; Addr <= MaxAddress; ++Addr)
  {
    if (!Put(0xFF, Addr)) break;
  }

  Console.Write(")");
  Console.EndLine();
}

/*
  Run EEPROM test

  We're reading all EEPROM and printing it's contents.
  Then increasing every byte by 1 and writing it back.
*/
void RunTest()
{
  ClearEeprom();

  PrintEeprom();

  //*
  using namespace me_Eeprom;

  // ( Read, modify, write, print

  Console.Write("( Writing ");

  for (TAddress Addr = MinAddress; Addr <= MaxAddress; ++Addr)
  {
    TUnit Byte;
    if (!Get(&Byte, Addr)) break;
    ++Byte;
    if (!Put(Byte, Addr)) break;
  }

  Console.Write(")");
  Console.EndLine();

  PrintEeprom();

  // )

  //*/
}

void setup()
{
  me_Uart::Init(me_Uart::Speed_115k_Bps);
  me_Eeprom::Init();

  Console.Print("[me_Eeprom] test.");

  RunTest();

  Console.Print("Done.");
}

void loop()
{
}

/*
  2025-07-12
  2025-07-13
*/
