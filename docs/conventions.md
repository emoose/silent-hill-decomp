## Naming Conventions
If a name is already known (eg. from some kind of SDK library or symbols of another title) that name should be used as-is, but guesses for names should try to follow the conventions below.

### Functions
Function names should be written in CamelCase, and try to follow the format:

`[SystemName]_[Noun][Verb]_[FunctionAddress]`

For example:

`Demo_GameGlobalsUpdate_8008F1A0`  
`FS_FileRead_80010F68`

This format allows us to easily sort functions alphabetically and have related functions kept grouped together.

The function address is included to make looking it up in the binary take slightly less steps, though may be removed if the project is ever made shiftable.

### Globals
Global variables should try using the same form as functions, but the address is optional for the benefit of keeping code tidier.

### Structures
Structures should have fields written in snake_case, with the field offset appended to it - keeping the offset as part of the name will allow us to more easily notice if the fields have moved around.

For example:

`int frame_counter_1C;`

Fields that are known to be accessed but without a known purpose should just be named `field_XYZ`, while fields that are completely unknown/padding bytes should be named as `unk_XYZ`.

Structures themselves should be named according to their usage, but if the usage isn't totally understood (or seems to be used for multiple things) then naming as `s_[GlobalAddress]` can be used if the structure is held at a static address.
