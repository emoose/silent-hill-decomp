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
Contributions are welcome, please read over the contents of [docs/](docs/) beforehand to learn the conventions used in this project.

If you would like to reserve a function, open a PR with the function or file name(s).

### Useful scripts

#### asm-differ
Before making changes it's recommended to build a clean version of the current matching code, the makefile will then copy the results of this build over to the `expected` directory.

This will allow `asm-differ` to be able to compare any future changes against the known-matching version for you.

While asm-differ is running it can also auto-build changes to the function, giving you a live view of how close it currently matches.

`asm-differ` can be ran by passing an overlay & function name over to it, eg:

`python3 tools/asm-differ/diff.py -mwo --overlay bodyprog vcRetMaxTgtMvXzLen`

#### decompile.py
The decompile.py script (from [sotn-decomp project](https://github.com/Xeeynamo/sotn-decomp)) can try to decompile a function for you using m2c and m2ctx, automatically inserting it into the functions .c file.

The script will tell you whether the decompiled function matches or not, for trivial functions it may be able to match straight away, usually it will need some massaging though.  
(eg. by adding structures or prototypes of functions called by it into header files beforehand)

`decompile.py` can be ran by just passing a function name over to it, eg:

`python3 tools/decompile.py vcRetMaxTgtMvXzLen`
