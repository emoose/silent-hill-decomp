#!/usr/bin/env python3

def add_custom_arguments(parser):
    parser.add_argument(
        "--overlay",
        default="SLUS_007.07",
        dest="overlay",
        help="Defines which overlay to use for the diff (main, dra, st/mad, etc.)",
    )

def apply_main(config, args):
    config['mapfile'] = f'build/SLUS_007.07.map'
    config['myimg'] = f'build/SLUS_007.07'
    config['baseimg'] = f'rom/image/SLUS_007.07'
    config['source_directories'] = ['src/main', 'include', 'asm/main']

def apply_bodyprog(config, args):
    config['mapfile'] = f'build/BODYPROG.BIN.map'
    config['myimg'] = f'build/BODYPROG.BIN'
    config['baseimg'] = f'assets/1ST/BODYPROG.BIN'
    config['source_directories'] = ['src/bodyprog', 'include', 'asm/bodyprog']

def apply(config, args):
    overlay = args.overlay or "SLUS_007.07"
    if overlay == "SLUS_007.07" or overlay == "main":
        apply_main(config, args)
    else:
        if overlay == "bodyprog":
            apply_bodyprog(config, args)
        config["arch"] = "mipsel"
        config["objdump_executable"] = "mipsel-linux-gnu-objdump"