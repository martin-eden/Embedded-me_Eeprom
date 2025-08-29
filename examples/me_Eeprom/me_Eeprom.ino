// [me_Eeprom] module test

/*
  Author: Martin Eden
  Last mod.: 2025-08-29
*/

/*
  Test reads and modifies EEPROM.

  In my Linux setup, board is reset after ~3 seconds after opening.

  To avoid being reset when writing data, we're waiting 5 seconds
  after startup.
*/

#include <me_Eeprom.h>

#include <me_BaseTypes.h>
#include <me_Console.h>
#include <me_Delays.h>

/*
  Print EEPROM contents. Helper function
*/
void PrintEeprom()
{
  Console.Print("( Reading");

  for (TAddress Addr = 0; Addr <= TAddress_Max; ++Addr)
  {
    TUnit Byte;

    if (!me_Eeprom::Get(&Byte, Addr))
      break;

    Console.Print(Byte);
  }

  Console.Print(")");
}

/*
  Fill EEPROM with given value
*/
void FillEeprom(
  TUint_1 Value
)
{
  Console.Write("( Filling with");
  Console.Print(Value);

  for (TAddress Addr = 0; Addr <= TAddress_Max; ++Addr)
  {
    if (!me_Eeprom::Put(Value, Addr))
      break;
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
  me_Eeprom::Init();

  FillEeprom(1);
  PrintEeprom();

  FillEeprom(2);
  PrintEeprom();

  FillEeprom(TUint_1_Max);
  PrintEeprom();
}

void setup()
{
  me_Delays::Delay_S(5);

  Console.Init();

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
