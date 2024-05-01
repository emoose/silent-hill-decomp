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

Under a Debian based distribution, you can install these with the following commands:
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

## Contemporary Games
Some similar Konami games from the same timeframe which may share code with SH, could be worth digging through prototypes/alternate releases:
- (PSX) **International Track & Field** / **ITF 2000**: SH contains unused graphics from it & seems to share very similar overlay/data handling code, likely has more in common too.
- (PS2) **ESPN International Track & Field**: sequel of the above with debug symbols available, seems to mostly be a C++ codebase, maybe a rewrite of the above, or a completely different engine.
- (PSX) **beatmania APPEND 5thMIX**: uses similar movie player code to SH but doesn't appear to share much else.
- (PSX) **Tokimeki Memorial \~forever with you\~**: earlier Konami PSX game, has partial debug symbols which unfortunately don't match its executable, making comparisons a bit harder.
- (PS2) **Silent Hill 2**: the sequel, prototypes are available with debug symbols but code doesn't appear to share much in common with SH1, though shared dev team members may mean similar code conventions with it.
