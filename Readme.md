# What

(2025-07)

ATmega328/P EEPROM interface.

This is continuation of writing hardware interfaces in C++. Bitfields
are nice.

## Stuff

* Interface
  * [Frontend][Interface_front]
  * [Backend][Interface_back]
* [Implementation][Implementation]
* [Example][Example]
* [Notes][Notes]

## Requirements

  * arduino-cli
  * bash

## Install/remove

This is low-level library which depends only of "me_BaseTypes".
However example depend on my other libraries. To save our time
I would advise to clone [GetLibs][GetLibs] repo and run it's code
to get all my stuff.

## See also

* [My other embedded C++ libraries][Embedded]
* [My other repositories][Repos]

[Interface_front]: src/me_Eeprom.h
[Interface_back]: src/me_Eeprom_Bare.h
[Implementation]: src/me_Eeprom.cpp
[Example]: examples/me_Eeprom/me_Eeprom.ino
[Notes]: extras/Notes.txt

[GetLibs]: https://github.com/martin-eden/Embedded-Framework-GetLibs

[Embedded]: https://github.com/martin-eden/Embedded_Crafts/tree/master/Parts
[Repos]: https://github.com/martin-eden/contents
