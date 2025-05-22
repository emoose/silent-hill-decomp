## Analysis Guide

Several options are available to help disassemble & analyze the game, the guide below explains loading the game/overlays into both **Ghidra** & **IDA Pro**, a guide for using **decomp.me** to create matching function decompilations is also included.

Ghidra is the most recommended due to its simple support for overlays, but it's useful to have other tools to check against too.

---

## **[Ghidra](https://github.com/NationalSecurityAgency/ghidra)**

Ghidra supports MIPS disassembly/decompilation, but a loader extension is needed to allow loading in PSX executables.

- Download the latest loader extension for your Ghidra version: [https://github.com/lab313ru/ghidra\_psx\_ldr](https://github.com/lab313ru/ghidra_psx_ldr)

- Copy the ZIP into Ghidra/Extensions/Ghidra/ folder.

- In Ghidra, go to **File > Install Extensions** and install the loader, then restart Ghidra.

- Load the main executable `SLUS_007.07` into Ghidra and open it in the code browser, when prompted to analyze, **cancel**.

- Head to **Tools > PSX Overlay Manager**.

- Load `BODYPROG.BIN` with:

   * Block Name: `bodyprog`
   * Start Address: `0x80024B60`

- Load any other overlays you're interested in from the `VIN` folder:

   * `MAP` files & `1ST/B_KONAMI.BIN` -> Start address: `0x800C9578`
   * `OPTIONS.BIN`, `SAVELOAD.BIN`, `STF_ROLL.BIN`, `STREAM.BIN` -> Start address: `0x801E2600`

- After loading the overlays, go to **Analysis > Auto Analyze**.

- Ensure **PsyQ Signatures** is checked (optionally, click it and set PsyQ version to 4.4.0)

- Start analysis.

If successful most functions will be identified and analyzed, though some may still be left undefined (especially map functions which are often only referenced by data).

You can use the `sym.*.txt` files from the decomp to help label more functions (PsyQ signature matching can also be unreliable for some funcs, our `sym.main.txt` and `sym.bodyprog.txt` files may be useful for naming them instead)

> [!NOTE]
> Calls/references to `bodyprog` functions may point to empty space in main executable memory instead of the `bodyprog` overlay area - individual calls can be fixed to point to `bodyprog` manually, but it's not clear if this can be fixed globally yet.

---

## **[IDA Pro](https://hex-rays.com/ida-pro)**

The paid version of IDA Pro supports MIPS disassembly/decompilation, and has support for PSX executables built-in.

Overlays are apparently supported but it's not clear how well that works, using separate databases per-map-overlay (ie: a base database with main/bodyprog loaded, and then copies of that with each map) may be more reliable for now.

- Open `SLUS_007.07` in IDA, it should be automatically detected as a PSX EXE.

- Once the main EXE is loaded, go to **File > Load File > Additional binary file**

- Select the overlay file and enter its start address.

   * Note: IDA requires addresses in 16-byte blocks (divide by `0x10`). For example, `0x80012340` -> Enter `0x8001234`

- Unfortunately as the address of map overlays ends in `8`, these need a workaround to load in:

   * Open **Segments** view
   * Resize the `bodyprog` segment to end at `0x800C9570`
   * Add 8 bytes of padding (`00`) to the start of the map overlay file
   * Load it at `0x800C957`
   * Resize the `bodyprog` segment back to end at `0x800C9578`

This should allow everything to line up correctly despite IDA's alignment restriction.

---

## **[decomp.me](https://decomp.me/)** / **[m2c](https://github.com/matt-kempster/m2c)**

decomp.me allows decompiling functions using m2c, while providing a live diff view that compares the compiled C code against the original assembly. You can edit C code directly in the browser and see changes in real time.

Each scratch is also publicly viewable and forkable, making it easy to collaborate on the same function.

(If you have a GitHub account you may want to login to it on decomp.me first, so that scratches will be credited to you.)

- On the decomp.me page, head to **New scratch** > Click **PlayStation** option > Under Presets, select **Silent Hill**

- Ignore the `Diff Label` field for now.

- Paste the function assembly (`.s` file) into the **Target Assembly** box.

   * `.s` files are generated after running `make setup` in the decomp project.
   * `Diff Label` field should auto-fill after pasting it in.

- In the **Context** box, paste in the `ctx.c` content for the `.c` file that includes the function:

   * Run `tools/m2ctx.py src/bodyprog/bodyprog.c` (change to the .c file that has `INCLUDE_ASM` line for the function)
   * Copy the contents of the generated `ctx.c` into the box

- Click **Create Scratch**

This should create a scratch for you with decompiled output from `m2c`, sometimes this can make very closely matching C code, though usually it might take a bit of work first.

Adding the overlay name to the beginning of the scratch is recommended to help keep track of each function (just a comment like `// MAP0_S00`)

If the function uses jump tables, decomp.me/m2c may ask for jtbl data before it can decompile:

- In this case, delete the scratch and start over with a new one.
- Before the function's assembly, include the jtbl_XXX data that m2c requested (can usually be found in one of the `.rodata.s` file for the `.c`):

  ```asm
  .section .rodata, "a"
  ; jump table data here (`dlabel jtbl_XXX` line through `.size jtbl_XXX`)

  .section .text, "a"
  ; original function code here
  ```
