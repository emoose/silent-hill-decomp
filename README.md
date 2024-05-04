# Silent Hill Decompilation Project

An in-progress decompilation of the 1.1 US release of Silent Hill on the Playstation 1.

## Building (Linux)

### Install build dependencies
The build process has the following package requirements:
- git
- build-essential
- binutils-mips-linux-gnu
- python3
- bchunk
- 7z

Under a Debian-based distribution (or Windows with a Debian-based WSL2 setup), you can install these with the following commands:
```
sudo apt update
sudo apt install git build-essential binutils-mips-linux-gnu python3 bchunk p7zip-full p7zip-rar
```

### Clone the repository
Clone `https://github.com/Vatuu/silent-hill-decomp` in whatever directory you wish. Make sure to clone recursively!
```
git clone --recursive https://github.com/Vatuu/silent-hill-decomp.git
cd silent-hill-decomp
```

### Install Python3 requirements
Run `pip3 install -r requirements.txt`

### Placing the ROM
Obviously, you will need to provide your own rom dump of the game. The required version is the NTSC-U 1.1 Version of Silent Hill.
If done correctly, you will end up with a .BIN and .CUE file. Both of these need to be placed inside the `rom/image` folder, and renamed to SLUS-00707.bin/.cue respectively.
SHA1 Hashes:
- .cue: `299D08DCB44E7516F394C3DD5BA40690AE33FD22` 84 Bytes
- .bin: `34278D31D9B9B12B3B5DB5E45BCBE548991ECBC7` 616,494,480 Bytes / 587 MiB

### Build the code
Run `make setup` to extract needed assets/code from the bin, if that succeeds, run `make` to build it.
Once build has finished a folder will be produced with the name `build`, inside this, you will find the output.

## Contributing
Contributions are welcome. If you would like to reserve a function, open a PR with the function or file name(s).

### Naming Conventions
If a name is already known (eg. from some kind of SDK library or symbols of another title) that name should be used, but guesses for names should try to follow the conventions below.

#### Functions
Function names should be written in CamelCase, and try to follow the format:

`[SystemName]_[Noun][Verb]_[FunctionAddress]`

For example:

`Demo_GameGlobalsUpdate_8008F1A0`  
`FS_FileRead_80010F68`

This format allows us to easily sort functions alphabetically and have related functions kept grouped together.

The function address is included to make looking it up in the binary take slightly less steps, though may be removed if the project is ever made shiftable.

#### Globals
Global variables should try using the same form as functions, but the address is optional for the benefit of keeping code tidier.

#### Structures
Structures should have fields written in snake_case, with the field offset appended to it - keeping the offset as part of the name will allow us to more easily notice if the fields have moved around.

For example:

`int frame_counter_1C;`

Fields that are known to be accessed but without a known purpose should just be named `field_XYZ`, while fields that are completely unknown/padding bytes should be named as `unk_XYZ`.

Structures themselves should be named according to their usage, but if the usage isn't totally understood (or seems to be used for multiple things) then naming as `s_[GlobalAddress]` can be used if the structure is held at a static address.

## Contemporaries
Konami games from the same timeframe may share code with SH, could be worth digging through prototypes/alternate releases:
-  **Tokimeki Memorial \~forever with you\~**: has partial debug symbols which unfortunately don't match its executable, making any comparisons a bit harder.
-  **beatmania APPEND 5thMIX**: partial source available, uses similar movie player code but doesn't appear to share much else, contains a Konami `SD` sound library that's completely different to the one used in SH.
-  **Pachinko Dream**: source available, doesn't appear to share much (if anything) with SH, but seems to employ similar "SYS_W" structures holding things like current game state index.
-  **International Track & Field** / **ITF2000**: SH contains unused graphics from it & seems to share very similar overlay/data handling code, likely has more in common too.
-  **Konami International Rally Racing**: unreleased game that contains MAP/SYM symbols, shares the same `SD` sound library as SH (albeit a slightly different version)
-  **ESPN International Track & Field (PS2)**: sequel of ITF2000 with debug symbols available, seems to mostly be a C++ codebase, maybe a rewrite, or a completely different engine.
-  **Silent Hill 2 (PS2)**: the sequel, prototypes are available with debug symbols but doesn't appear to share much in common with SH1, though shared dev team members could mean similar code conventions within.

(there are many other Konami games that could share code too - they released a *lot* during the PSX/PS2 era - any Konami prototype releases may be useful to look through!)
